// Author: Seth Roller

# include <stdio.h>
# include <stdlib.h>
# include <math.h> 

// defined all functions
void read_doubles(int n, double a[n]);

void max_min(int n, double a[n], double *max, double *min);

double sum(int n, double a[n]);

double mean(int n, double a[n]);

double median(int n , double a[n]);

double variance(int n, double a[n]);

double stddev(int n, double a[n]);

int compare(const void *x, const void *y);

int main(int argc, double *argv[])
{
  int count;
  double maximum;
  double minimum;
  double maxy;
  scanf("%d", &count);
  double numbers[count];
  
  read_doubles(count, numbers);
  max_min(count, numbers, &(maximum), &(minimum));

  printf("\n");
  printf("count: %42d\n", count);
  printf("min: %44.8lf\n", minimum);
  printf("max: %44.8lf\n", maximum);
  printf("sum: %44.8lf\n", sum(count, numbers));
  printf("median: %41.8lf\n", median(count, numbers));
  printf("mean: %43.8lf\n", mean(count, numbers));
  printf("variance: %39.8lf\n", variance(count, numbers));
  printf("stddev: %41.8lf\n", stddev(count, numbers));
  
}

void read_doubles(int n, double a[n])
{
  double readIn;
  int inc = 0;
  while (inc < n)
  {
    scanf("%lf", &readIn);
    a[inc] = readIn;
    inc++;

  }
  
}

void max_min(int n, double a[n], double *max, double *min)
{
  qsort(a, n, sizeof(double), compare);
  *max = a[n - 1];
  *min = a[0];
  
}

double sum(int n, double a[n])
{
  int i = 0;
  double summing = 0;
  while (i < n)
  {
    summing += a[i];
    i++;
  }

  return summing;

}

double mean(int n, double a[n])
{
  int i = 0;
  double added = 0;
  while (i < n)
  {  
    added += a[i];
    i++;
  }
  
  double avg = added / n;
  return avg;

}


double median(int n, double a[n])
{
  qsort(a, n, sizeof(double), compare);
  if (n % 2 == 0)
    return ((a[n / 2] + a[(n / 2) - 1]) / 2) ;
  else
    return (a[(n - 1) / 2]);

}


double variance(int n, double a[n])
{
  
  int i = 0;
  double added = 0;
  while (i < n)
    {
      added += a[i];
      i++;
    }

  double avg = added / n;
  double sum = 0;
  
  for (int i = 0; i < n; i++)
  {
    sum = sum + ((a[i] - avg) * (a[i] - avg));
  }

  return (sum / n);
}

double stddev(int n, double a[n])
{
  int i = 0;
  double added = 0;
  while (i < n)
    {
      added += a[i];
      i++;
    }

  double avg = added / n;
  
  double sumSqrTerms = 0.0;
  double term;
  
  for (int i = 0; i < n; i++)
  {
    term = a[i] - avg;
    sumSqrTerms += term * term;
    
  }
  
  double standard = sqrt(sumSqrTerms / (double)n);
  return standard;

}

int compare(const void *x, const void *y)
{
  double xx = * (double *) x;
  double yy = * (double *) y;
  if (xx < yy) return -1;
  else if (xx > yy) return 1;
  else return 0;
  
}
