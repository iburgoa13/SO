#!/bin/bash 

if [ -e $1 ]; then
	echo “Tipo de fichero: ”
	if [ -f $1 ]; then 
		echo "	fichero regular"  
	elif [ -d $1 ]; then 
		echo "	directorio"  
    elif [ -e $1 ]; then 
        echo "	FIFO/pipe"  
    elif [ -b $1 ]; then  
    	echo "	dispositivo de bloques" 
    elif [ -c $1 ]; then  
    	echo "	dispositivo de caracteres" 
   	elif [ -S $1 ]; then  
   		echo "	socket" 
   	elif [ -h $1 -o -L $1 ]; then  
        echo "	enlace simbólico" 
    fi

	    echo "Permisos:"						
	if [ -r $1 ]; then 
		echo "	lectura" 
	fi
	if [ -w $1 ]; then 
		echo "	escritura" 
	fi
	if [ -x $1 -a -d $1 ]; then 
		echo "	paso" 
	elif [ -x $1 ]; then 
		echo "	ejecución" 
	fi

    
	echo "Fecha actualización:"	$(date -r $1 +%F)

	exit 0	
else
	echo “El archivo $1 no existe”
	exit 1
fi
