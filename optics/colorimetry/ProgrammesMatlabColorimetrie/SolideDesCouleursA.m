function SolideDesCouleursA(a,DispTrM)
% SolideDesCouleursA - Trace le solide des couleurs réels en perspective (taille Ajustable)
% USAGE:SolideDesCouleursA(a)
% a: scalaire réel > 1, le facteur d'extension au-delà du spectrum locus 3D
% DispTrM: [OPTIONNEL] scalaie logique, affiche on non le triangle de Maxwell (défaut: ¤true¤)
% NOTA: XYZ reliés à yzx_Matlab ou inversement xyz_Matlab associés à ZXY  (Y [luminance V] est vertical, z_Matlab)
% L'objet “Solide des couleurs réelles” a le Tag 'SolideCR'
% © Hervé SAUER - Institut d'Optique Graduate School - 13 novembre 2010 + 23 février 2016

if ~exist('DispTrM','var')
  DispTrM=true;
end
  

hf1=figure('position',[300  250  800  800],'PaperOrientation','portrait'); 

haxX=plot3([0 0 0 0 0],[0 1.1 1.05 1.1 1.05],[0 0 -0.025 0 0.025],'k','linewidth',2); % axe X
hold on
text(0,1.15,0,'X','HorizontalAlignment','center','FontSize',12)
haxY=plot3([0 0 0 0 0],[0 0 -0.025 0 0.025],[0 1.1 1.05 1.1 1.05],'k','linewidth',2); % axe Y
text(0,0,1.15,'Y','HorizontalAlignment','center','FontSize',12)
haxZ=plot3([0 1.1 1.05 1.1 1.05],[0 0 -0.025 0 0.025],[0 0 0 0 0],'k','linewidth',2); % axe Z
text(1.15,0,0,'Z','HorizontalAlignment','center','FontSize',12)

hCCZ=plot3([1 1 1 1 1],[0 1 1 0 0],[0 0 1 1 0],'k'); % trois faces du cube des couleurs
hCCX=plot3([0 1 1 0 0],[1 1 1 1 1],[0 0 1 1 0],'k'); %              "         "
hCCY=plot3([0 1 1 0 0],[0 0 1 1 0],[1 1 1 1 1],'k'); %              "         "

hCCXY=fill3([0 0 0 0 0],[0 1 1 0 0],[0 0 1 1 0],[0.8 0.8 0.8]);% face arrière XY(Z=0) du cube des couleurs

axis off
axis equal
xlabel('Z')
ylabel('X')
zlabel('Y')
view(115,31)

if DispTrM
  htM=fill3([1 0 0],[0 1 0],[0 0 1],[0.8 0.4 0.4]);%[0.9 0.5 0.5]); % TRIANGLE DE MAXWELL (rose transparent)
  alpha(htM,0.7)
  set(htM,'EdgeColor','none')
end

%hDG=plot3([0 1],[0 1],[0 1],'color',[0.5 0.5 0.5],'linewidth',2); % DIAGONALE DES GRIS


% lxyzb=csvread(xyzbar_CIE1931_1nm.txt');
lxyzb=load('xyzbar2deg_CIE1931_1nm.txt');
PAS=5; % nm (entier)
%Lbda=lxyzb(1:PAS:end,1);
xyzbar=lxyzb([360 430 440 450 460 470:PAS:620 630 650 780 830 360]-360+1,2:end); % ## AVEC tracé de la dernière à la première longueur d'onde (droite des pourpres)

Sxyzbar=sum(xyzbar,2);


hSLTM=plot3(xyzbar(:,3)./Sxyzbar,xyzbar(:,1)./Sxyzbar,xyzbar(:,2)./Sxyzbar,'linewidth',2,'color',[0.5 0.5 0.5]);
hSLZ0=plot3(zeros(size(Sxyzbar)),xyzbar(:,1)./Sxyzbar,xyzbar(:,2)./Sxyzbar,...
  'linewidth',2,'color',[0.4 0.0 0.0],'linestyle','--');

%---------------------------- 
% hf2=copyobj(hf1,0); % nouvelle figure accrochée à (nécessairement) root [0].
% 
% figure(hf1)
% drawnow
% set(hf1,'Position',get(hf1,'Position')+[30 -30 0 0])

%a=1.2; %%## c'est un argument d'entrée maintenant
SC.vertices=[0 0 0; ... le sommet du cône en vertex n°1
  a*xyzbar(:,3)./Sxyzbar  a*xyzbar(:,1)./Sxyzbar  a*xyzbar(:,2)./Sxyzbar];

L=length(Sxyzbar);
% SC.faces=NaN(L,L-1);
% SC.faces(1:L-1,1:3)=[ones(L-1,1) (2:L).' (3:L+1).'];
% SC.faces(L,:)=(2:L).'; % face plane // plan de Maxwell au dessus du solide des couleurs réels
% ^ Ça marche pas, une partie de la face du dessus est noire (erreur ou bug?)
SC.faces=[ones(L-1,1) (2:L).' (3:L+1).'];
% sans la face du dessus, la surface est plus compréhensible...

% colormap([0.8 1 0.8; 0 0 1])
% SC.facevertexcdata=[ones(L-1,1);2]; % tous le solide en couleur 1 sauf la face plane du dessus en couleur 2
%hSC=patch(SC,'EdgeColor','k', 'FaceColor','flat', 'CDataMapping','direct');

hSC=patch(SC,'EdgeColor',[0.3 0.3 0.3],'FaceColor',[0.7 0.7 0.7],'Tag','SolideCR');

set(hSC,'FaceLighting','Gouraud',...
      'AmbientStrength',0.4)
alpha(hSC,0.5)
material dull
%alpha(0.5)

  
light('Position',[1 1 2],'Style','infinite');
%delete([hCCXY hSLZ0 hDG])

set(hCCXY,'FaceColor',[0.99 0.99 1.00])

view(66,31)
% figure(hf1)

set(gca,'Projection','perspective')
cameratoolbar('Show')
cameratoolbar('SetMode','orbit')
cameratoolbar('SetCoordSys','z') % z Matlab == Y CIE
% NOTA: XYZ reliés à yzx_Matlab ou inversement xyz_Matlab associés à ZXY  (Y [luminance V] est vertical, z_Matlab)

drawnow







