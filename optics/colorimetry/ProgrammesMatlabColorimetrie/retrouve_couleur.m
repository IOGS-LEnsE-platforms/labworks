M = zeros(3,3);
M(1,1) = 3324.2431;
M(2,1) = 1461.2049;
M(3,1) = 41.4171;
M(1,2) =947.6965;
M(2,2) =4188.3036;
M(3,2) =708.2202;
M(1,3)= 2299.0363;
M(2,3) =915.0579;
M(3,3) =13344.4388;

Vblanc = M*[1;1;1];

Vcible = [3794.6030;3596.8321;6902.4536];

Vaction = M\Vcible;

Vaction = floor(Vaction*255);
Vorange = [1748.0980;1500.3680;85.6147];
Vaction_orange = M\Vorange;

Vrouge = [68.2408;45.9594;0.7240];

Vaction_rouge = M\Vrouge;

Me = zeros(3,3);
Me(1,1) = 25.4273;
Me(2,1) = 14.5790;
Me(3,1) = 8.3933;
Me(1,2) =24.2051;
Me(2,2) =43.8349;
Me(3,2) =11.1431;
Me(1,3)= 13.4801;
Me(2,3) =6.7791;
Me(3,3) =58.3098;

% Vaction_ecran = Me\Vorange;
% 
% Vaction_ecran = floor((Vaction_ecran.^(1/2.2)*255;

vcible = [400;400;200];
Vaction = M\vcible;

v = floor(Vaction*255)





