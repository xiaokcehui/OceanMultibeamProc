#!/bin/bash
#               GMT EXAMPLE 41
#               $Id: example_41.sh 16750 2016-07-09 05:44:02Z pwessel $
#
# Purpose:      Illustrate typesetting of legend with table
# GMT modules:  gmtset, pscoast, pslegend, psxy
# Unix progs:   cat, rm
#
ps=example_41.ps

gmt set FONT_ANNOT_PRIMARY 12p FONT_LABEL 12p

gmt pscoast -R130W/50W/8N/56N -JM5.6i -B0 -P -K -Glightgray -Sazure1 -A1000 -Wfaint -Xc -Y1.2i --MAP_FRAME_TYPE=plain > $ps
gmt pscoast -R -J -O -K -EUS+glightyellow+pfaint -ECU+glightred+pfaint -EMX+glightgreen+pfaint -ECA+glightblue+pfaint >> $ps
gmt pscoast -R -J -O -K -N1/1p,darkred -A1000/2/2 -Wfaint -Cazure1 >> $ps
gmt psxy -R -J -O -K -Skmy_symbol/0.1i -Cmy_color.cpt -W0.25p -: my_data.txt >> $ps
gmt pslegend -R0/6/0/9.1 -Jx1i -Dx3i/4.5i+w5.6i+jBC+l1.2 -C0.05i -F+p+gsnow1 -B0 -O my_table.txt -X-0.2i -Y-0.2i >> $ps
