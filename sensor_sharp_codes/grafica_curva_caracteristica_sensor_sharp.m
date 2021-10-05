d = [10,12.5,15,17.5,20, 25,30,40,50,60,70,80];
medida = [5, 4.28,3.6, 3.10,2.82, 2.32, 1.98, 1.60, 1.33, 1.20, 1.08, 0.95];
ec = polyfit(medida, d, 4)
%dp = 10:1:80;
%vp=polyval(ec,dp);
%plot(vp,dp)
%hold on
plot(medida, d,'or','markerfacecolor','r')
