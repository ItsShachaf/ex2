/******************
Name:Shachaf Segal
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int choice,faceSize;
	char mouth, eyes, nose;
	printf("Choose an option: "
		   "\n 1.Happy face"
		   "\n 2.Balanced number"
		   "\n 3.Generous number "
		   "\n 4.Circle of joy "
		   "\n 5.Happy numbers"
		   "\n 6.Festival of laughter "
		   "\n 7.Exit \n");//menu
	printf("Please enter your choice: ");//delete this
	scanf( "%d",&choice);
	while (choice<1 || choice>7) {
		printf("Please enter a valid choice: ");
		scanf( "%d",&choice);
		switch (choice) {//switch is the best way to handle multiple connected choices
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/
			case 1:
				printf("\n Please enter a face size:");
			scanf("%d",&faceSize);
			while(faceSize<=0 || faceSize%2==0) {
				printf("the face size needs to be a positive odd number, please try again:");
				scanf("%d",&faceSize);
			}

			printf("Enter a symbol from your keyboard to represent the eyes,mouth and  nose:");
			scanf(" %c  %c %c", &eyes,&nose,&mouth);

			printf("%c",eyes);
			for (int i=0; i<faceSize; i++) {
				printf(" ");
			}
			printf("%c \n",eyes);//printing the eyes according to the mission

			for (int i=0; i<(faceSize+1)/2;i++) {
				printf(" ");
			}
			printf("%c",nose);//printing the nose as requested
			printf("\n");

			printf("\\");
			for (int i=0; i<faceSize;i++) {
				printf("%c",mouth);
			}//printing the mouth
			printf("/");
			break;

			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/
			case 2:
				int balance,digit=0,balance10,rightsum=0,leftsum=0;
			printf("Please enter a number");
			scanf("%d",&balance);
			while (balance<=0) {
				printf("The number needs to be bigger than 0:");
				scanf("%d",&balance);
			}
			balance10=balance;
			while (balance10>0) {
				balance10 /=10;
				digit++;
			}//counting how many digits in the number
			balance10=balance;
			for (int i=0; i<digit/2; i++) {
				rightsum+=balance10 % 10;
				balance10 /=10;
			}//summarizing the right side of the number to the middle
			if (digit%2==1) {
				balance10 /=10;
			}//checking if there is an odd amount of digit so I can ignore it in the sum
			for (int i=0; i<digit/2; i++) {
				leftsum+=balance10 % 10;
				balance10 /=10;
			}//summarizing the left side of the number to the middle
			if (leftsum==rightsum) {
				printf("this number is balanced and brings harmony");
			}//checking if they are equal
			else {
				printf("this number isn't balanced and destroyes harmoney!");
			}
			break;
			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/
			case 3:
				int num,sumdiv=0;
			printf("Please enter a number:");
			scanf("%d",&num);
			while (num<=0) {
				printf("The number needs to be bigger than 0:");
				scanf("%d",&num);
			}
			for (int i=1; i<num; i++) {
				if (num%i==0) {
					sumdiv+=i;
				}
			}//checking the sum of divisor numbers
			if (sumdiv>num) {
				printf("This number is generous!!!!");
			}//if the sum of the divisors is bigger it's a generous number
			else {
				printf("This number DOES NOT SHARE!!!!");//this number is evil
			}
			break;
			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/
			case 4:
				int isprime;
			printf("Please enter a number:");
			scanf("%d",&isprime);
			while (isprime<=0) {
				printf("Please enter a number bigger than 0:");
				scanf("%d",&isprime);
			}//checking that the number is bigger than 0
			for (int i=2; i<isprime; i++) {
				if (isprime%i==0) {
					printf("This number brings death and misery!!! >=[");
					break;
				}//checking if the number has other divisors othe1 than itself and 1
				if (i==isprime-1){
					printf("This number brings sunshine and rainbows =]");
					break;
				}//if it doesn't it's a prime number
			}

			break;


			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/
			case 5:
				//i've tried it over and over again, you can see my trail and obvious error- Shachaf
				int n,sumdigitsquare=0,happydigit=0;
			printf("Please enter a number:");
			scanf("%d",&n);
			while (n<=0) {
				printf("Please enter a number bigger than 0:");
				scanf("%d",&n);
			}

			printf("Happy numbers untill we get to the input number:");
			for (int i=1; i<=n; i++) {
				while (n>0) {
					happydigit=n%10;
					sumdigitsquare+=happydigit*happydigit;
					n/=10;
				}

			}
			if (sumdigitsquare==1) {printf("%d",&sumdigitsquare);
				//	else {}
				//	}

				break;
				//while (happynum>0){
				//for (int i=0; i<happynum; i++) {
				//happynumdigit+=i;
				// sumdigitsquare+=i^2;
				//if ((i^2)==1) {
				//	sumdigitsquare+=i^2;
				//printf("%d",&sumdigitsquare);
				// 	}
				//else {
				//	printf("1");
				//	}
				//	happydigit++;
				//sumdigitsquare+=(happynum%10)^2;
				//happynum/=10;
				//}



				break;
				//throwaway=happynum;
				//while (sumdigitsquare!=1 && sumdigitsquare!=throwaway) {
				// throwaway=happynum;
				//sumdigitsquare=0;
				//while (throwaway>0) {
				//sumdigitsquare+=(throwaway%10)^2;
				//throwaway/=10;
				//happynumdigit++;

				//	}

				//	printf("",&sumdigitsquare);
				// }
				//	if (sumdigitsquare==1) {
				//		printf("This number is happy !!!!");
				//	}
				//	else if (sumdigitsquare!=1) {
				//		printf("This number is sad !!!!");
				//	}




				// Festival of Laughter: Prints all the numbers between 1 the given number:
				// and replace with "Smile!" every number that divided by the given smile number
				// and replace with "Cheer!" every number that divided by the given cheer number
				// and replace with "Festival!" every number that divided by both of them
				/* Example:
				6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
				*/
				case 6:
					int cheer, smile,max;
				printf("Please enter a cheer number:");
				scanf("%d",&cheer);
				printf("Please enter a smile number:");
				scanf("%d",&smile);
				printf("Please enter a max number:");
				scanf("%d",&max);
				while (cheer==smile || cheer<=0 || smile<=0) {
					printf("only 2 positive numbers are aloud, try again:");
					printf("Please enter a cheer number:");
					scanf("%d",&cheer);
					printf("Please enter a smile number:");
					scanf("%d",&smile);
				}//checking that the numbers are different from one another and that they are positive
				while (max<=0) {
					printf("Please choose a positive maximum number");
					scanf("%d",&max);
				}//checking if the user didn't insert a negative or 0 maximum
				for (int i=1; i<=max; i++) {
					if ((i%cheer==0) && (i%smile!=0)) {
						printf("cheer!\n");
					}
					else if ((i%smile==0) && (i%cheer!=0)) {
						printf("smile!\n");
					}
					else if ((i%smile==0) && (i%cheer==0)) {
						printf("festival!\n");
					}
					else  {printf("%d \n",i);}
				}//printing and checking which numbers have the cheer and/or smile numbers as divisors
				break;

				case 7:
					printf("Thank you for visiting  numeria");//if the user decided to not choose anything
				break;

			}
		}
		return 0;
	}
}

