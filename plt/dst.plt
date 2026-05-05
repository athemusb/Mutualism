set terminal tikz size 8.4cm, 4.5cm fontscale 0.8 fulldoc \
header "\\usepackage{amsmath}"
set output "dst.tex"

set yrange [0.0:6]
set xrange [0:1000]
set ytics 0.0, 1.0 offset 1
set xtics 0.0, 100 
set xlabel offset 0.0, 0.0 "$t$"
set ylabel offset 0.5, 0.0 "$\\rho_i$"
set key at graph 0.1, 0.55 left reverse Left samplen 0.3 horizontal width 1


plot "../dat/abund.dat" u ($0/100):($1) w l lw 1.5 lc rgb "#00ff00" t"veg",\
     "../dat/abund.dat" u ($0/100):($2) w l lw 1.5 lc rgb "#ff00ff" t"pol",\

unset output
