#!/bin/bash
#		GMT EXAMPLE 04
#		$Id: example_04.sh 17741 2017-03-21 21:52:29Z jluis $
#
# Purpose:	3-D mesh and color plot of Hawaiian topography and geoid
# GMT modules:	grdcontour, grdimage, grdview, psbasemap, pscoast, pstext
# Unix progs:	echo, rm
#
ps=example_04.ps
gmt makecpt -C255,100 -T-10/10/10 -N > zero.cpt
gmt grdcontour HI_geoid4.nc -R195/210/18/25 -Jm0.45i -p60/30 -C1 -A5+o -Gd4i -K -P \
	-X1.25i -Y1.25i > $ps
gmt pscoast -R -J -p -B2 -BNEsw -Gblack -O -K -TdjBR+o0.1i+w1i+l >> $ps
gmt grdview HI_topo4.nc -R195/210/18/25/-6/4 -J -Jz0.34i -p -Czero.cpt -O -K \
	-N-6+glightgray -Qsm -B2 -Bz2+l"Topo (km)" -BneswZ -Y2.2i >> $ps
echo '3.25 5.75 H@#awaiian@# R@#idge@#' | gmt pstext -R0/10/0/10 -Jx1i \
	-F+f60p,ZapfChancery-MediumItalic+jCB -O >> $ps
rm -f zero.cpt
#
ps=example_04c.ps
gmt grdimage HI_geoid4.nc -I+a0+nt0.75 -R195/210/18/25 -JM6.75i -p60/30 -Cgeoid.cpt -E100 \
	-K -P -X1.25i -Y1.25i > $ps
gmt pscoast -R -J -p -B2 -BNEsw -Gblack -O -K >> $ps
gmt psbasemap -R -J -p -O -K -TdjBR+o0.1i+w1i+l --COLOR_BACKGROUND=red --FONT=red \
	--MAP_TICK_PEN_PRIMARY=thinner,red >> $ps
gmt psscale -R -J -p240/30 -DJBC+o0/0.5i+w5i/0.3i+h -Cgeoid.cpt -I -O -K -Bx2+l"Geoid (m)" >> $ps
gmt grdview HI_topo4.nc -I+a0+nt0.75 -R195/210/18/25/-6/4 -J -JZ3.4i -p60/30 -Ctopo.cpt \
	-O -K -N-6+glightgray -Qc100 -B2 -Bz2+l"Topo (km)" -BneswZ -Y2.2i >> $ps
echo '3.25 5.75 H@#awaiian@# R@#idge@#' | gmt pstext -R0/10/0/10 -Jx1i \
	-F+f60p,ZapfChancery-MediumItalic+jCB -O >> $ps
