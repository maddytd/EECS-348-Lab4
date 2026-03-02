#include <stdio.h>

float celsius_to_fahrenheit(float c) { return (9.0f / 5.0f) * c + 32.0f; }
float fahrenheit_to_celsius(float f) { return (5.0f / 9.0f) * (f - 32.0f); }
float celsius_to_kelvin(float c)     { return c + 273.15f; }
float kelvin_to_celsius(float k)     { return k - 273.15f; }
float fahrenheit_to_kelvin(float f)  { return celsius_to_kelvin(fahrenheit_to_celsius(f)); }
float kelvin_to_fahrenheit(float k)  { return celsius_to_fahrenheit(kelvin_to_celsius(k)); }

void categorize_temperature(float celsius) {
    printf("\nCategory: ");
    if      (celsius < 0)   printf("Freezing     - Dress in heavy layers.\n");
    else if (celsius <= 10) printf("Cold         - Wear a jacket.\n");
    else if (celsius <= 25) printf("Comfortable  - Enjoy the outdoors!\n");
    else if (celsius <= 35) printf("Hot          - Stay hydrated.\n");
    else                    printf("Extreme Heat - Stay indoors!\n");
}

int main(void) {
    float temp, result, celsius_equiv;
    int from, to;

    printf("Enter temperature: ");
    scanf("%f", &temp);

    printf("Input scale  (1=Fahrenheit, 2=Celsius, 3=Kelvin): ");
    scanf("%d", &from);

    printf("Target scale (1=Fahrenheit, 2=Celsius, 3=Kelvin): ");
    scanf("%d", &to);

    /* Validate */
    if (from == to) { printf("Error: Input and target scales are the same.\n"); return 1; }
    if (from == 3 && temp < 0) { printf("Error: Kelvin cannot be negative.\n"); return 1; }

    /* Convert to Celsius for categorization */
    if      (from == 1) celsius_equiv = fahrenheit_to_celsius(temp);
    else if (from == 2) celsius_equiv = temp;
    else                celsius_equiv = kelvin_to_celsius(temp);

    /* Perform conversion */
    if      (from == 1 && to == 2) result = fahrenheit_to_celsius(temp);
    else if (from == 1 && to == 3) result = fahrenheit_to_kelvin(temp);
    else if (from == 2 && to == 1) result = celsius_to_fahrenheit(temp);
    else if (from == 2 && to == 3) result = celsius_to_kelvin(temp);
    else if (from == 3 && to == 1) result = kelvin_to_fahrenheit(temp);
    else                           result = kelvin_to_celsius(temp);

    printf("\nResult: %.2f => %.2f\n", temp, result);
    categorize_temperature(celsius_equiv);

    return 0;
}