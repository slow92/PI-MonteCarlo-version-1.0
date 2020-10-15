#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

	/*Dla boku 10 000, i probek 10^8
	PI=3.040364
	PI2=3.141587
	*/

int main(){
	char nw[20];
	char typ[]="P2";
	char nazwa[]="#PI";
	int szarosc=255;
	double poleKwadratu,poleKola,rKwadrat;//koniec naglowka
	int j,x,y,z;//zmienne w for(){}
	int n,m,bok,r;//wymiary obrazu
	int **tab;//nasz obraz
	int vx,vy,vxy;//odleglowsci punktu od srodka obrazu/kola po x/y i geometryczna
	int sx,sy;//losowe wspolrzedne puktow
	int zarodek;
	int i,v,vv;//i-liczba losowanych pkt,v-liczba pkt w kole
	double PI,b,PI2;//PI-szukana stala,b-stosunek pola kola do pola kwadratu
	FILE *fp;
	FILE *fg;
	//
	puts("Podaj wymiar boku skwantowanego obrazu:\n");
	scanf("%d",&bok);
	if(bok%2==0){
		r=bok/2;
	}
	else{
		r=(bok+1)/2;
	}
	printf("%d\n",r);
	n=bok;
	m=bok;
	poleKwadratu=n*m;
	rKwadrat=r*r;
	tab=(int**)malloc(n*sizeof(int*));
	for(z=0;z<n;++z)
		tab[z]=(int*)malloc(m*sizeof(int));
	//
	//tutaj rysujemy obrazek
	//
	vv=0;
	for(y=0;y<n;y++){
		for(x=0;x<m;x++){
				vx=r-x;
				vy=r-y;
				vxy=pow(vx,2)+pow(vy,2);
			if(sqrt(vxy)<=r){
				tab[x][y]=0;
				vv++;
			}
			else
			tab[x][y]=125;
			}
		}
	tab[r][r]=255;
	//
	//zapisz rysowany obraz
	//
	puts("Zapisz obraz jako:  (.pgm)\n");
	scanf("%s",&nw);
	//
	if ((fp=fopen(nw, "w"))==NULL) {
     	printf ("Nie mogê otworzyæ do zapisu!\n");
     	exit(1);
     	}
	fprintf(fp,"%s\n",typ);
	fprintf(fp,"%s\n",nazwa);
	fprintf(fp,"%d %d\n",n,m);
	fprintf(fp,"%d\n",szarosc);
	for(y=0;y<n;y++){
		for(x=0;x<m;x++){
			fprintf(fp,"%d ",tab[x][y]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	//
	//losowe punkty
	//
	puts("Podaj liczbe probek\n");
	scanf("%d",&i);
	zarodek=time(NULL);
	srand(zarodek);
	v=0;
for(j=0;j<i;j++){

		sx=rand()%n;
		sy=rand()%m;
				vx=r-sx;
				vy=r-sy;
				vxy=pow(vx,2)+pow(vy,2);
			if(sqrt(vxy)<=r){
				tab[sx][sy]=255;
				v++;
			}
			else
			tab[sx][sy]=0;
}
	//
	//zapisz obraz po symulacji
	//
	puts("Zapisz obraz jako:  (.pgm)\n");
	scanf("%s",&nw);
	//
	if ((fg=fopen(nw, "w"))==NULL) {
     	printf ("Nie mogê otworzyæ do zapisu!\n");
     	exit(1);
     	}
	fprintf(fg,"%s\n",typ);
	fprintf(fg,"%s\n",nazwa);
	fprintf(fg,"%d %d\n",n,m);
	fprintf(fg,"%d\n",szarosc);
	for(y=0;y<n;y++){
		for(x=0;x<m;x++){
			fprintf(fg,"%d ",tab[x][y]);
		}
		fprintf(fg,"\n");
	}
	fclose(fg);
	//
	//liczba PI
	//
	b=v*pow(i,-1);
	poleKola=poleKwadratu*b;
	PI=poleKola/rKwadrat;
	PI2=vv*pow(rKwadrat,-1);
	printf("Liczba PI wyznaczona metoda Monte Carlo to:%f\n",PI);
	printf("Liczba PI wyznaczona zliczaniem punktow to:%f\n",PI2);

	system("PAUSE");
	return 0;
}
