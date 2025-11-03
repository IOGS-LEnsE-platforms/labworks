%% Chargement des fichier issu du spectrocolorimètre
[FichierDeMesures, Chemin] = uigetfile('*.csv', 'Choisir le fichier contenant les mesures');
M = readtable(strcat(Chemin,FichierDeMesures));

%% Récupération des données colorimétriques
%Indice de Rendu des Couleurs
CRIstr=cell2mat(M{19,{'Var2'}});
CRI=str2num(CRIstr);

Tstr=cell2mat(M{5,{'Var2'}});
T=str2num(Tstr);

% Coordonnées chromatiques xyz CIE31
xstr=cell2mat(M{12,{'Var2'}});
x=str2num(xstr);
ystr=cell2mat(M{13,{'Var2'}});
y=str2num(ystr);
zstr=cell2mat(M{14,{'Var2'}});
z=str2num(zstr);

% Tristimulus XYZ
Xstr=cell2mat(M{9,{'Var2'}});
X=str2num(Xstr);
Ystr=cell2mat(M{10,{'Var2'}});
Y=str2num(Ystr);
Zstr=cell2mat(M{11,{'Var2'}});
Z=str2num(Zstr);


%%Spectres en deux résolutions (5nm et 1nm)
%Résolution 5nm
LR = M{35:115,{'Var2'}};
LRmat=cell2mat(LR);
SpectreLR=str2num(LRmat);

%Résolution 1nm
HR = M{116:516,{'Var2'}};
HRmat=cell2mat(HR);
SpectreHR=str2num(HRmat);

plot(linspace(380,780,length(SpectreLR)),SpectreLR,'r',linspace(380,780,length(SpectreHR)),SpectreHR,'b', 'LineWidth',2);
xlabel('Longueur d''onde (nm)'), ylabel('Densité spectrique (mW.m^{-2}.nm^{-1})'),
title({'Composantes spectrales de la source' ; texlabel(FichierDeMesures,'literal')})
text(400, max(SpectreLR)/1.2 ,{['IRC=', CRIstr],['x=', xstr], ['y=', ystr], ['T=', Tstr] })

%%Pilotage de la LED
s = serial('COM7');
fopen(s);
Question='Commande des Sources (ex : 255 255 255 0 0 ) ?';
Reponse=input(Question,'s');
fprintf(s,strcat(Reponse,'\n')); 
fclose(s);



%% Synthèse des couleurs avec le bandeau de LEDs
% Tristimulus XYZ mesurés avec le spectrocolorimètre

%Boîte à lumière
RougeXYZ=[2543;1132.2;25.3];  % 255 0 0
VertXYZ=[699.4 ; 2983.7;467.1];  % 0 255 0
BleuXYZ=[1527;791.9; 9025.3];     % 0 0 255 

MatXYZ=[RougeXYZ, VertXYZ, BleuXYZ];
MatXYZInv=inv(MatXYZ);

%LEDIkea=[245.8; 225.5; 99.7];

%LEDsTri=MatXYZInv*LEDIkea
% Pour 'copier' la couleur de la LED Ikea, envoyer un multiple de 
% ce vecteur en commande des LEDs

%FiltreBleu=[125.2;197;214.2];
%LEDsTri2=MatXYZInv*FiltreBleu

%FiltreBleuNewLED=[218.45; 220.93 ; 834.17];
%LEDTri3=MatXYZInv*FiltreBleuNewLED


LED2=[4432.3; 4368.3;5530.4];
LED1=[4286.3;4044.5 ; 8094.4];

LED1etFiltres=[100.8; 97.3; 3];
LED1etFiltreBleu=[1282 ;1263 ; 5222];
LED1etFiltreOrange=[1386 ; 936.9 ; 15.3];
LED1etFiltreRouge=[1401.6 ; 804.5 ; 1470.2];
LED1etFiltreRouge=[70.2 ; 41.1 ; 69.7]; % REF1 a 10 au lieu 255...

LEDTriREF1=MatXYZInv*LED1*255
LEDTriREF2=MatXYZInv*LED2;
LEDTriREF2=LEDTriREF2*255/max(LEDTriREF2)



LEDTriFiltres=MatXYZInv*LED1etFiltres;
LEDTriFiltres=LEDTriFiltres*255


LEDTriFiltreBleu=MatXYZInv*LED1etFiltreBleu;
LEDTriFiltreBleu=LEDTriFiltreBleu*255


LEDTriFiltreOrange=MatXYZInv*LED1etFiltreOrange;
LEDTriFiltreOrange=LEDTriFiltreOrange*255


LEDTriFiltreRouge=MatXYZInv*LED1etFiltreRouge;
LEDTriFiltreRouge=LEDTriFiltreRouge*255


Cible=[800 ; 800; 400 ];%0.4 0.4
%Cible=[700 ; 720; 580 ]; %0.35 0.36
LEDTriCible=MatXYZInv*Cible*255;




%% Test de l'écran
Dim=800;
ImR=zeros(Dim,2*Dim,3);
ImV=zeros(Dim,2*Dim,3);
ImB=zeros(Dim,2*Dim,3);

ImR(:,:,1)=1*ones(Dim,2*Dim,1);
ImV(:,:,2)=ImR(:,:,1);
ImB(:,:,3)=ImR(:,:,1);


close all,
figure(1), image(ImR), axis image, axis off
figure(2), image(ImV), axis image, axis off
figure(3), image(ImB), axis image, axis off


figure(5), image(10/255*ImR+50/255*ImV+80/255*ImB), axis image, axis off
figure(6), image(ImR+150/255*ImV+10/255*ImB), axis image, axis off






%% Synthèse des couleurs avec l'écran
% Sans correction du gamma

%Mesures au spectrocoloriùètre
EcranXYZR=[48.8;28.2;16.3];
EcranXYZV=[46.2; 83.6;21.7];
EcranXYZB=[25.4; 12.9;108.5];

MatEcranXYZ=[EcranXYZR, EcranXYZV, EcranXYZB];
MatEcranXYZInv=inv(MatEcranXYZ);

RVBecranFiltreOrange=MatEcranXYZInv*LED1etFiltreOrange
RVBecranFiltreBleu=MatEcranXYZInv*LED1etFiltreBleu
RVBecranFiltres=MatEcranXYZInv*LED1etFiltres/2
RVBecranFiltres=RVBecranFiltres.^(0.45)

RVBecranFiltreR=255^2/274*(MatEcranXYZInv*LED1etFiltreRouge).^(0.45)
RVBecran=[1 0.18 0.7]; %avec correction gamma



%RVBecran=[1 0.02 0.46]; sans correction gamma
% Cible => (x,y)= (0.4, 0.4);
% X Y Z proportionnel à (0.4, 0.4, 0.2)

%Cible=[80; 80; 40 ];
%Cible=[100;100;100];
%Cible=Cible/3;

%FiltreRoseNewLED=[88.8;52.5;101.1];
%RVBecran=MatEcranXYZInv*FiltreRoseNewLED

%LEDnew=[250;236;450];
%RVBecran=(MatEcranXYZInv*LEDnew);%.^(0.45);

%RVBecran=(MatEcranXYZInv*Cible).^(0.45);


M=1;
Im(:,:,1)=M*RVBecran(1)*ones(Dim,2*Dim,1);
Im(:,:,2)=M*RVBecran(2)*ones(Dim,2*Dim,1);
Im(:,:,3)=M*RVBecran(3)*ones(Dim,2*Dim,1);



figure(5), image(Im), axis image, axis off

