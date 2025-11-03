function [ R,V,B ] = Entree( X,Y,Z )
     MatLED=[3240.4568 930.7770 2286.1273;1425.1267 4072.3462 920.0659;89.4927 690.8607 13297.5973];
    INV=inv(MatLED);
    V=[X;Y;Z];
    M=INV*V;
    sum=M(1)+M(2)+M(3)
    

%     [A,D,C]=INV*[X,Y,Z]
%     S=A+D+C
%     R=255*(A/S)
%     V=255*(D/S)
%     B=255*(C/S)
end

