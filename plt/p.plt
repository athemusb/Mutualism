Nx=  ` sed -n "/#define Nx / p" ../rps.h | cut -f3 -d" " `
NF=  ` sed -n "/#define NF / p" ../rps.h | cut -f3 -d" " `
l=  ` sed -n "/#define l / p" ../rps.h | cut -f3 -d" " `
dx= l/Nx

set terminal pngcairo size 1080, 1081 crop 
set xtics 0.0, 5
set ytics 0.0, 1.0
set xrange [0.5:l]
set yrange [0:3]
set key at 18, 2.9 maxrows 1
set xlabel "(m)"


i=0
while (i < NF){
	set output sprintf("fig/%d.png", i)
	plot sprintf("../dat/p/%d.dat", i) using ($1*(dx)):2 with p pt 7 lt 1 t"poli",\
	     sprintf("../dat/v/%d.dat", i) using ($1*(dx)):2 with p pt 7 lt 2 t"veg"
	unset output
	
	i=i+1
}
