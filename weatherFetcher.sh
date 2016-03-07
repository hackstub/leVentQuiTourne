#!/bin/bash

url="https://api.worldweatheronline.com/free/v2/marine.ashx?key=885d356dded1bd408e5669e81b8c1&q=35.340,25.180&format=xml&windspeedKmph"
curl $url > query.xhtml

read_dom () {
    local IFS=\>
    read -d \< ENTITY CONTENT
}

function fetch {
	i=0
	while read_dom; do
	    if [[ $ENTITY = $1 ]]; then
		echo "$1[$i]"
		echo $CONTENT
		((i++))
	    fi
	done < query.xhtml > $1.txt
}

fetch "winddirDegree"
fetch "windspeedKmph"
