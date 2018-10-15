#include<iostream.h>
#include<conio.h>
#include<math.h>

void main() {
	clrscr();
   int a[10],b[10],t,i;
   cin>>t;
   for(i=0; i<t; i++) {
	cin>>a[i]>>b[i];}
   for(i=0; i<t; i++) {
	cout<<pow(a[i],b[i])<<"\n";}

   getch();}
