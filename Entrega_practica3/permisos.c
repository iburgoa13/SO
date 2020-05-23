#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
struct stat sb;

if (argc != 2) {
    fprintf(stderr, "*** utiliza: %s <fichero>\n", argv[0]);
    exit(1);
}
if (stat(argv[1], &sb) == -1) {
     perror("stat");
     exit(0);
}

if (S_ISREG(sb.st_mode)) {
    	 	printf("%s es un fichero\n", argv[1]);
} 
else {
if (S_ISDIR(sb.st_mode)) {
           printf("%s es un directorio\n", argv[1]);

			/*TAMAÑO DEL MISMO*/
			printf("Tamaño fichero: %ld bytes\n", sb.st_size);
      		/*PERMISOS PROPIETARIO*/
    		if (((S_IRUSR)&(sb.st_mode))==(S_IRUSR)) 
                	printf("con permiso de lectura para el propietario\n"); 
    		if (((S_IWUSR)&(sb.st_mode))==(S_IWUSR))            		printf("con permiso de escritura para el propietario\n");     	 	if (((S_IXUSR)&(sb.st_mode))==(S_IXUSR))            		printf("con permiso de paso para el propietario\n");
	
	       /*PERMISOS GRUPO*/
    

			if (((S_IRGRP)&(sb.st_mode)) == (S_IRGRP)) {
				printf("con permiso de lectura para el grupo\n");
			}
			if (((S_IWGRP)&(sb.st_mode)) != (S_IWGRP)) {
				printf("sin permiso de escritura para el grupo\n");
			}
			if (((S_IXGRP)&(sb.st_mode)) == (S_IXGRP)) {
				printf("con permiso de paso para el grupo\n");
			}


          /*PERMISOS OTROS*/
			if (((S_IROTH)&(sb.st_mode)) == (S_IROTH)) {
				printf("con permiso de lectura para todos\n");
			}
			if (((S_IWOTH)&(sb.st_mode)) != (S_IWOTH)) {
				printf("sin permiso de escritura para todos\n");
			}
			if (((S_IXOTH)&(sb.st_mode)) == (S_IXOTH)) {
				printf("sin permiso de paso para todos\n");
			}


           /*FECHA Y HORA DE LA ULTIMA MODIFICACION*/
			printf("Última modificación del fichero: %s",ctime(&sb.st_mtime));

    }
}
 exit(0);
}


