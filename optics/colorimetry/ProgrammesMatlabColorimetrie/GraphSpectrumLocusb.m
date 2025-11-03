function GraphSpectrumLocusb
% GraphSpectrumLocus - dessine le spectrum locus dans le diagramme de chromaticité CIE 1931
%                    - draw the spectrum locus in the CIE 1931 chromaticity diagram.
% USAGE: GraphSpectrumLocus
  
% IOGS - 24 novembre 2016 - Hervé Sauer


% petit: vecteur des lambdas [nm] où il y aura un petit tiret perpendiculaire
% grand: vecteur des lambdas [nm] où il y aura un grand(gros) tiret perpendiculaire
% annot: vecteur des lambdas [nm] où il y aura une annotation texte de la lambda

petit=[400:20:460 470:2:480  481:1:600 602:2:620 640:20:780];
grand=[360 400 450 470:10:620 780 830];
annot=[360 450 470:10:620 830];

xyzbar=load('xyzbar2deg_CIE1931_1nm.txt'); % BàO SupOptique
% (471 lignes × 4 colonnes [lbda,xbar,ybar,zbar])
lbda=xyzbar(:,1); % nm, (360:1:830).'
xbar=xyzbar(:,2);
ybar=xyzbar(:,3);
sumxyzbar=sum(xyzbar(:,2:4),2);
SLx=xbar./sumxyzbar;
SLy=ybar./sumxyzbar;

%figure('Units','centimeters','Position',[2 3 20 24])
%set(gcf,'PaperOrientation','portrait','PaperPositionMode','auto')
%figure('Position',[200 120 650 650])

%set(gca,'Units','centimeters','Position',[2.5 3 16 18])

plot(SLx,SLy,'k','HandleVisibility','off') % HandleVisibility off pour que la courbe n'apparaisse pas dans la légende
hold on
axis equal
xlim([0 0.8])
ylim([0 0.9])
xlabel('x')
ylabel('y')

xti=0:0.05:0.8;
yti=0:0.05:0.9;
ha=gca;
ha.XTick=xti;
ha.YTick=yti;
%ha.XAxis.TickLabelFormat='%4.2f';
ha.XAxis.TickLabel=sprintf('%4.2f\n\n',xti(1:2:end));
ha.YAxis.TickLabelFormat='%4.2f';
ha.XMinorTick='on';
ha.YMinorTick='on';
ha.TickDir='out';
ha.XAxis.MinorTickValues=setdiff(0:0.01:0.8,xti);
ha.YAxis.MinorTickValues=setdiff(0:0.01:0.9,yti);
title({'Diagramme de chromaticité xy CIE 1931 {\itet spectrum locus annoté [en nm]}',...
       'xy CIE 1931 chromaticity diagram {\itand [nm] labelled spectrum locus}', ...
       ' '},'FontWeight','normal','FontSize',10)

grid on


%% Tracé des annotations du spectrum locus

petit=setdiff(petit,grand);
Annote(petit,0.01,0.3)

Annote(grand,0.02,1)

if any(~ismember(annot,grand))
  error('Les longueurs d''onde à annoter ne sont pas toutes dans la liste des grands marqueurs')
end

annot=unique(annot);

for j=1:length(annot)
  k=annot(j)-360+1; % on se ramène en indice de lbda (rappel: lbda===(360:1:830).')
  text(SLx(k),SLy(k),sprintf(' %3d',annot(j)))
end


%% fonction locale imbriquée:
  function Annote(LbdaAnnot,long,ep)
    % Annote -  annote le spectrum locus
    % USAGE: Annote(LbdaAnnot,long,ep)
    % LbdaAnnot: vecteur des lambdas à annoter (nombres entiers, en nm)
    % long:     longueur des petits traits perpendiculaires au spectrum locus (en unité xy du diag de chromaticité)
    % ep:       épaisseur du trait (en point)

    LbdaAnnot=unique(LbdaAnnot);
    
    
    if any(~ismember(LbdaAnnot,lbda))
      error('Les longueurs d''onde à marquer ne sont pas toutes dans les points de calculs du spectrum locus (360:1:830)')
    end


    kA=LbdaAnnot-360+1; % Rappel: lbda===(360:1:830).'

    kAp1=kA+1;
    kAp1(kAp1>length(lbda))=length(lbda);

    kAm1=kA-1;
    kAm1(kAm1<1)=1;

    %vecteur perpendiculaire au spectrum locus
    vy=SLx(kAp1)-SLx(kAm1);
    vx=-(SLy(kAp1)-SLy(kAm1));
    vx=vx(:).';  % forcé en vecteur LIGNE
    vy=vy(:).';  %      "        "
    norme=sqrt(vx.^2+vy.^2);
    vx=vx./norme*long/2;
    vy=vy./norme*long/2;

    SLxkA=SLx(kA);SLxkA=SLxkA(:).';
    SLykA=SLy(kA);SLykA=SLykA(:).';
    
    xA=[SLxkA-vx;SLxkA+vx;SLxkA+NaN];xA=xA(:);
    yA=[SLykA-vy;SLykA+vy;SLykA+NaN];yA=yA(:);

    plot(xA,yA,'k','LineWidth',ep,'HandleVisibility','off') % HandleVisibility off pour que la courbe n'apparaisse pas dans la légende)

  end

end



