#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bloom.h"
int VECT_SIZE=800;
int K=3;
int main(int argc, char** argv){
VECT_SIZE=atoi(argv[3]);
printf("%d",VECT_SIZE);
seiveInitial();

FILE *file = fopen(argv[1], "r");
FILE * fp;
fp = fopen (argv[2],"w");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL) return NULL; //could not open file
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    code = malloc(f_size);

    while ((c = fgetc(file)) != EOF) {
        code[n++] = (char)c;

    }

    code[n] = '\0';




struct bloom * bloomFilter=(struct bloom *) calloc(1,sizeof(struct bloom));
bloomFilter->bloom_vector = (int *) calloc((VECT_SIZE / NUM_BITS + 1),sizeof(int) );
char *nodes = strtok (code,"\n");
            while (nodes != NULL)
            {
                //add(list, atoi(nodes));
				//char * temp=strtok(nodes," ");

                int first=0;
                int i=0;
                int size_str=strlen(nodes);
                while(i<=size_str){
                    if((int)nodes[i]!=32){
                        first++;
                    }else{
                    i++;
                    break;
                    }
                    i++;

                }
                char * node_id=(char *)malloc( sizeof(char)*(first+1)  );
                memcpy(node_id, nodes , first );
                node_id[first]='\0';
                fprintf (fp, "%s",node_id);
		//printf("%s\n",node_id);
                //printf("%s",node_id);
                first=i;
                int len=0;
                while(i<=size_str){
                        if((int)nodes[i]!=32){
                            len++;
                        }else{
                            char * node_temp=(char *)malloc( sizeof(char)*(len+1)  );
                            memcpy(node_temp, nodes+first , len );
                            node_temp[len]='\0';
                            
                            int f=atoi(node_temp);
				//printf("%d\n",f);
                            insert(f,bloomFilter);
				
                            first=i+1;
                            len=0;
				
                        }
                        i++;
                        if(i==size_str){
                            char * node_temp=(char *)malloc( sizeof(char)*(len+1)  );
                            memcpy(node_temp, nodes+first , len );
                            node_temp[len]='\0';

                            int f=atoi(node_temp);
                            insert(f,bloomFilter);

                        }


                }
                for (i=0;i<(VECT_SIZE / NUM_BITS + 1);i++){
                    if(i==(VECT_SIZE / NUM_BITS) ){
                    fprintf (fp, " %d\n",bloomFilter->bloom_vector[i]);
                    }else{
                    fprintf (fp, " %d",bloomFilter->bloom_vector[i]);
                    }
                }
                init(bloomFilter);
		nodes = strtok (NULL, "\n");
            }
return 1;
}


