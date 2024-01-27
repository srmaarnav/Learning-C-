//Kolmogorov Smirnov Test

#include <stdio.h>
#include <conio.h>
#define da 0.26

double dplus(double num[], double d1[], int length, double n) {
    for (int i = 0; i < length; i++) {
        d1[i] = ((i + 1) / n) - num[i];
    }
    double d1max = d1[0];
    for (int i = 0; i < length; i++) {
        if (d1max <= d1[i]) {
            d1max = d1[i];
        }
    }
    printf("D+ = %f\n", d1max);
    return d1max;
}

double dminus(double num[], double d2[], int length, double n) {
    for (int i = 0; i < length; i++) {
        d2[i] = (num[i] - (i) / n);
    }
    double d2max = d2[0];
    for (int i = 0; i < length; i++) {
        if (d2max <= d2[i]) {
            d2max = d2[i];
        }
    }
    printf("D- = %f\n", d2max);
    return d2max;
}

void kst(double num[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (num[i] > num[j]) {
                double temp;
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    double d1[length];
    double d2[length];
    double n = (double) length;
    double d1max = dplus(num, d1, length, n);
    double d2max = dminus(num, d2, length, n);
    double dplus = d1max;
    double dminus = d2max;
    double d;
    if (dplus > dminus) {
        d = dplus;
    } else {
        d = dminus;
    }
    printf("D = %f\n", d);
    printf("\nThe tabulated value for D is 0.26.");
    if(d<da)
    {
    	printf(" The distribution is uniform as d(oberved) <= da(tabulated).");
	}
	else
	{
		printf("The distribution is not uniform.");
	}
}

int main() {
    int n;
    double dvalue1;
    printf("Enter number of elements to compute for tests: \t");
    scanf("%d", &n);
    double num[n];
    double dp, dn;
    int i;
    printf("\n\nEnter the numbers: \n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &num[i]);
    }
    kst(num, i);
    return 0;
}

