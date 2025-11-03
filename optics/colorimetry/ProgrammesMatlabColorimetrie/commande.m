function [R,V,B]=commande(Xcible,Ycible,Zcible)

M=[3038 867 2075; 1340 3785 836; 76 627 12067]; % matrice M LED de synthèse de couleur

W=[Xcible;Ycible;Zcible]; % matrice de la source cible

[R;V;B]=inv(M)*W % matrice M LED
