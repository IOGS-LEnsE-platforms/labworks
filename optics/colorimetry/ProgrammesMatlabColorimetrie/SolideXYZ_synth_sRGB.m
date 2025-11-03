function SolideXYZ_synth_sRGB
% SolideXYZ_synth_sRGB - affiche le solide des couleurs synthétisable sRGB dans XYZ avec le solide des couleurs réelles
% Créé deux figures
% L'objet “Solide des couleurs réelles” a le Tag 'SolideCR' dans les deux graphiques
% L'objet “Solide des couleurs synthétisables sRGB” dans le 2ème graphique a le Tag 'Solide_sRGB'
% NOTA: XYZ reliés à yzx_Matlab ou inversement xyz_Matlab associés à ZXY  (Y [luminance] est vertical, z_Matlab)


%%
R=rgb2xyz([1 0 0]);
r=R/sum(R);
fprintf(1,'Primaire Rouge: x=%8.6f, y=%8.6f, Y=%8.6f\n',r(1:2),R(2));
V=rgb2xyz([0 1 0]);
v=V/sum(V);
fprintf(1,'Primaire Verte: x=%8.6f, y=%8.6f, Y=%8.6f\n',v(1:2),V(2));
B=rgb2xyz([0 0 1]);
b=B/sum(B);
fprintf(1,'Primaire Bleue: x=%8.6f, y=%8.6f, Y=%8.6f\n',b(1:2),B(2));
W=rgb2xyz([1 1 1]);
w=W/sum(W);
fprintf(1,'Blanc écran W : x=%8.6f, y=%8.6f, Y=%8.6f\n',w(1:2),W(2));
D65=whitepoint('d65');
d65=D65/sum(D65);
fprintf(1,'Illuminant D65: x=%8.6f, y=%8.6f, Y=%8.6f\n',d65(1:2),D65(2));
%M=[R;V;B].';

%%

SolideDesCouleursA(1.4)
% NOTA: XYZ reliés à yzx_Matlab ou inversement xyz_Matlab associés à ZXY  (Y [luminance] est vertical, z_Matlab)
hold on

plot3([0 W(3)],[0 W(1)],[0 W(2)],'k:','linewidth',3) % ZXY

plot3([0 R(3)],[0 R(1)],[0 R(2)],'r','linewidth',3) % ZXY
plot3([0 V(3)],[0 V(1)],[0 V(2)],'g','linewidth',3) % ZXY
plot3([0 B(3)],[0 B(1)],[0 B(2)],'b','linewidth',3) % ZXY

plot3([B(3) R(3)+B(3) R(3)],[B(1) R(1)+B(1) R(1)],[B(2) R(2)+B(2) R(2)],'m','linewidth',3) % ZXY
plot3([V(3) R(3)+V(3) R(3)],[V(1) R(1)+V(1) R(1)],[V(2) R(2)+V(2) R(2)],'y','linewidth',3) % ZXY
plot3([V(3) B(3)+V(3) B(3)],[V(1) B(1)+V(1) B(1)],[V(2) B(2)+V(2) B(2)],'c','linewidth',3) % ZXY

plot3([R(3)+B(3) W(3)],[R(1)+B(1) W(1)],[R(2)+B(2) W(2)],'m','linewidth',3) % ZXY
plot3([R(3)+V(3) W(3)],[R(1)+V(1) W(1)],[R(2)+V(2) W(2)],'y','linewidth',3) % ZXY
plot3([B(3)+V(3) W(3)],[B(1)+V(1) W(1)],[B(2)+V(2) W(2)],'c','linewidth',3) % ZXY


plot3([r(3) v(3) b(3) r(3)],[r(1) v(1) b(1) r(1)],[r(2) v(2) b(2) r(2)],'color',[0.8 0.8 0.8]) % triangle couleur synth sur Tri Maxwl
plot3(w(3),w(1),w(2),'*w','MarkerSize',8) % D65 sur Tri Maxwl
plot3([ 0    0    0    0  ],[r(1) v(1) b(1) r(1)],[r(2) v(2) b(2) r(2)],'--','color',[0.9 0.9 0.9]) % triangle couleur synth sur sur XY(Z=0)
plot3(0 ,w(1),w(2),'*w') % D65 sur XY(Z=0)

title({'Parallélépipède des couleurs synthétisables de l''{\itespace sRGB}', ...
       '\rmreprésenté avec le solide des couleurs réels dans le cube XYZ CIE 1931'}) 

%rotate3d on
drawnow
hax1=gca;
%%


SolideDesCouleursA(1.4,false)
% NOTA: XYZ reliés à yzx_Matlab ou inversement xyz_Matlab associés à ZXY  (Y [luminance] est vertical, z_Matlab)

plot3([ 0    0    0    0  ],[r(1) v(1) b(1) r(1)],[r(2) v(2) b(2) r(2)],'--','color',[0.5 0.5 0.5]) % triangle couleur synth sur sur XY(Z=0)
plot3(0 ,w(1),w(2),'*w') % D65 sur XY(Z=0)


p=@(v) v([3 1 2]); % PERMUTATION xyz_Matlab associés à ZXY

hold on


SsRGB.vertices=[0 0 0        ; % 1
                p(R)            ; % 2
                p(V)            ; % 3
                p(B)            ; % 4
                p(V+B)          ; % 5 cyan
                p(R+B)          ; % 6 magenta
                p(R+V)          ; % 7 jaune
                p(W)     ]      ; % 8

SsRGB.FaceVertexCData=[0 0 0
                       1 0 0
                       0 1 0
                       0 0 1
                       0 1 1
                       1 0 1
                       1 1 0
                       1 1 1];
                     
SsRGB.faces=[1 2 7 3; % face 0RjV = jaune sombre
             1 2 6 4; % face 0RmB = magenta sombre
             1 3 5 4; % face 0VcB = cyan sombre
             8 6 2 7; % face WmRj = rouge clair
             8 5 3 7; % face WcVj = vert clair
             8 5 4 6; % face WcBm = bleu clair
             ];
% parallélépipède quelconque, 8 sommets, 6 faces.


hSsRGB=patch(SsRGB,'EdgeColor',[0.3 0.3 0.3],'FaceColor','interp','Tag','Solide_sRGB');

set(hSsRGB,'FaceLighting','Gouraud',...
      'AmbientStrength',0.9)
%alpha(hSsRGB,0.5)
material dull

light('Position',[0 3 1],'Style','infinite');
light('Position',[1 0 4],'Style','infinite');
%NOTA: XYZ reliés à yzx_Matlab ou inversement xyz_Matlab associés à ZXY  (Y [luminance] est vertical, z_Matlab)


title({'Parallélépipède des couleurs synthétisables de l''{\itespace sRGB}', ...
       '\rmreprésenté avec le solide des couleurs réels dans le cube XYZ CIE 1931'}) 

     
plot3([0 R(3)],[0 R(1)],[0 R(2)],'r','linewidth',3,'Tag','vecteurR') % ZXY
plot3([0 V(3)],[0 V(1)],[0 V(2)],'g','linewidth',3,'Tag','vecteurV') % ZXY
plot3([0 B(3)],[0 B(1)],[0 B(2)],'b','linewidth',3,'Tag','vecteurB') % ZXY


%rotate3d on
drawnow
hax2=gca;
%global hlink
hlink=linkprop([hax1 hax2],{'CameraPosition','CameraUpVector'});
set(gcf,'UserData',hlink)
%rotate3d on %% puisque 'orbit' camera validé par SolideDesCouleursA


