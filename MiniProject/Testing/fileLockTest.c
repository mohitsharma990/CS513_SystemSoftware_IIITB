#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#include "../AllStructures/allStruct.h"

int main()
{
    struct Customer temp;

    // struct Customer c1 =  {101, 1000, "Jaimin", "password", 1};
    // struct Customer c2 =  {102, 2000, "Raj", "password", 1};
    // struct Customer c3 =  {103, 3000, "Jainish", "password", 1};
    // struct Customer c4 =  {104, 4000, "Rohan", "password", 1};
    // struct Customer c5 =  {105, 5000, "Mohit", "password", 1};
    // struct Customer c6 =  {106, 6000, "Bhargav", "password", 1};

    int fd = open("customer.txt", O_CREAT | O_RDWR, 0777);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    // write(fd, &c1, sizeof(c1));
    // write(fd, &c2, sizeof(c2));
    // write(fd, &c3, sizeof(c3));
    // write(fd, &c4, sizeof(c4));
    // write(fd, &c5, sizeof(c5));

    // Set file pointer to beginning    
    // lseek(fd, 0, SEEK_SET);

    // Set file pointer to end
    // lseek(fd, 0, SEEK_END);

    // while(read(fd, &temp, sizeof(temp)) != 0)
    // {
    //     printf("Name: %s\n", temp.customerName);
    //     printf("password: %s\n", temp.password);
    //     printf("Account Number: %d\n", temp.accountNumber);
    //     printf("Balance: %.2f\n", temp.balance);
    //     printf("Status: %d\n", temp.activeStatus);
    // }



    int srcAcc = 104, dstAcc = 101;
    int sf = 0, df = 0; 
    
    off_t soff = -1, doff = -1;     
    while(read(fd, &temp, sizeof(temp)) > 0)
    {
        if(temp.accountNumber == srcAcc)
        {
            soff = lseek(fd, -sizeof(temp), SEEK_CUR);
            sf = 1;
            read(fd, &temp, sizeof(temp));
            printf("Inside SRC\n");
        }
        if(temp.accountNumber == dstAcc)
        {
            doff = lseek(fd, -sizeof(temp), SEEK_CUR);
            df = 1;
            read(fd, &temp, sizeof(temp));
            printf("Inside DST\n");
        }
        printf("Inside While\n");
        if(sf && df)
            break;
    }

    lseek(fd, soff, SEEK_SET);
    read(fd, &temp, sizeof(temp));
    printf("%d\n", temp.accountNumber);
    close(fd);

    return 0; 
}
