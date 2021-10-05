clc
clear all
close all
clear s a 
a = arduino();

%m = 500;
%for n=1:m
%    v(n) = readVoltage(a, 'A0');
%end

%n = [1:m];
%plot(n, v)
n = 1
set(gcf, 'currentchar', '1')
while get(gcf, 'currentchar')=='1'
    v(n) = readVoltage(a, 'A0');
    disp(v(n));
    n=n+1;
end
n= [1:n-1];
plot(n, v)