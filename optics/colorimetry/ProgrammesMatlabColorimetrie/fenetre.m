function fenetre(R,G,B)
%% Affiche un rectangle dont la couleur est déterminée par les paramètres 
% R G Et B (compris entre 0 et 255)
Dim=800;
ImR=zeros(Dim,2*Dim,3);
ImV=zeros(Dim,2*Dim,3);
ImB=zeros(Dim,2*Dim,3);

ImR(:,:,1)=1*ones(Dim,2*Dim,1);
ImV(:,:,2)=ImR(:,:,1);
ImB(:,:,3)=ImR(:,:,1);
figure, image(R/255*ImR+G/255*ImV+B/255*ImB), axis image, axis off
