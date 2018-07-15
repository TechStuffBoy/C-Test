//#include<stdio.h>
//#include<conio.h>
//
//
///* Apply the constructor attribute to myStartupFun() so that it
//    is executed before main() */
//void myStartupFun (void) __attribute__ ((constructor));
//
//
///* Apply the destructor attribute to myCleanupFun() so that it
//   is executed after main() */
//void myCleanupFun (void) __attribute__ ((destructor));
//
//
//
//int main (void)
//{
//	int ch;
//	setbuf(stdout, NULL);
//	printf ("hello\n");
//
//	while(1) {
//		printf("Enter val of ch\n");
//		scanf("%d", &ch);
//		printf("Val of ch = %d\n",ch);
//		if(ch==1)
//			break;
//	}
//	return 0;
//}
//
///* implementation of myStartupFun */
//void myStartupFun (void)
//{
//	printf ("startup code before main()\n");
//}
//
///* implementation of myCleanupFun */
//void myCleanupFun (void)
//{
//	printf ("cleanup code after main()\n");
//}
