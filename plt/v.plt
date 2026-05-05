Nx=  ` sed -n "/#define Nx / p" ../rps.h | cut -f3 -d" " `
NF=  ` sed -n "/#define NF / p" ../rps.h | cut -f3 -d" " `

set terminal pngcairo size 1081, 1081 crop 
set xtics 0.0, 100
set ytics 0.0, 1.0 
set xrange [0.5:Nx]
set yrange [0:5]
unset key


i=0
while (i < NF){
	set output sprintf("fig/v/%d.png", i)
	plot sprintf("../dat/v/%d.dat", i) using 1:2 with l lw 2 t""
	unset output
	
	i=i+1
}
