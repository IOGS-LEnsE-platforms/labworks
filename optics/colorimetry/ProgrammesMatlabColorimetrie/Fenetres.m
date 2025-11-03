%% Test de l'écran
Dim=800;
ImR=zeros(Dim,2*Dim,3);
ImV=zeros(Dim,2*Dim,3);
ImB=zeros(Dim,2*Dim,3);

ImR(:,:,1)=1*ones(Dim,2*Dim,1);
ImV(:,:,2)=ImR(:,:,1);
ImB(:,:,3)=ImR(:,:,1);

figure, image(ImR), axis image, axis off
figure, image(ImV), axis image, axis off
figure, image(ImB), axis image, axis off
