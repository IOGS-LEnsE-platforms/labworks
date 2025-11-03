%% Chargement des fichiesr issu du spectrocolorimètre
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
xlabel('Longueur d''onde (nm)'), ylabel('Eclairement énergétique spectrique (mW.m^{-2}.nm^{-1})'),
title({'Composantes spectrales de la source' ; texlabel(FichierDeMesures,'literal')})
text(400, max(SpectreLR)/1.2 ,{['IRC=', CRIstr],['x=', xstr], ['y=', ystr], ['T=', Tstr,'K'] })