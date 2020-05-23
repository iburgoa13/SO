#!/bin/bash
# Comprobar número de parámetros introducidos  
if [ ! "$#"  -eq 1 ]  
then 
        echo "¡¡ Error !!  Uso: "$0" nom_dir" 
        break 
fi 
  if [ -d "$1" ] 
  then 
          ls -lR "$1" | grep "^d"  
  else 
          echo "No existe el directorio $1" 
  fi
