#include<stdio.h>
#include<conio.h>
//---------------------------- Currency Dictionary ----------------------------

const char *dictionary[28] = {
    "USD",
    "BDT",
    "EUR",
    "GBP",
    "INR",
    "CAD",
    "AUD",
    "DKK",
    "FJT",
    "GHS",
    "HUF",
    "JPY",
    "KES",
    "KPW",
    "KRW",
    "LYD",
    "MXN",
    "NZD",
    "OMR",
    "PKR",
    "QAR",
    "RUB",
    "SGD",
    "TRY",
    "UAH",
    "VND",
    "YER",
    "ZMW",
};

//---------------------------- Keywords Dictionary ----------------------------

const char *dictionary2[4] = {
    "KG",
    "POUNDs",
    "Ounces",
    "GRAM",
};

//---------------------------- Length Unit Dictionary ----------------------------

const char *unit_Names[8] = {
    "MM",
    "CM",
    "M",
    "KM",
    "IN",
    "FT",
    "YD",
    "MI",
};

int shouldExit() {
    int q;
    system("color F0");
    printf("                     \n");
    printf("                      ");
    printf("Do you wanna continue? ([1] Yes / [2] No) \n");
    printf("                     \n");
    printf("                      ");
    scanf("%d", &q);
    return q;

};

//---------------------------- Currency Conversion Rates ----------------------------

const float conversionRates[28][28] = {
//             USD|    BDT|    EUR|    GBP|   INR|   CAD|   AUD|   DKK|   FJD|   GHS|    HUF|    JPY|    KES|     KPW|     KRW|   LYD|   MXN|   NZD|   OMR|    PKR|    QAR|     RUB|   SGD|    TRY|     UAH|      VND|    YER|   ZMW|
/*USD*/    {     1,  95.16,   1.00,   0.85, 82.76,  1.37,  1.58,  7.53,  2.31, 13.90, 419.13, 148.88, 121.25, 900.001, 1433.15,  5.00, 19.92, 19.92,  0.39, 218.71,   3.64,   62.10,  1.42,  18.61,   36.67,    36.67, 250.25, 15.90},  // USD to Currency
/*BDT*/    { 0.011,      1,  0.010, 0.0089,  0.82, 0.014, 0.016, 0.075, 0.023,  0.14,   4.16,   1.48,   1.20,    8.96,   14.21, 0.050,  0.20, 0.017,0.0038,   2.17,  0.036,    0.61, 0.014,   0.18,    0.36,   246.20,   2.48,  0.16},  // BDT to Currency
/*EUR*/    {  1.00,  95.51,      1,   0.85, 81.82,  1.36,  1.56, 0.075,  2.28, 13.73, 413.95, 146.85, 119.60, 885.149, 1415.50,  4.93, 19.65,  1.73,  0.38, 215.76,   3.59,   61.15,  1.40,  18.35,   36.16, 24496.44, 246.76, 15.68},  // EUR to Currency
/*GBP*/    {  1.18, 112.57,   1.18,      1, 93.56,  1.55,  1.79,  8.51,  2.61, 15.68, 474.22, 168.21, 136.83, 1020.48, 1622.71,  5.64, 22.50,  1.98,  1.98, 246.92,   4.11,   70.06,  1.61,  21.01,   41.38, 28039.11, 282.45, 17.95},  // GBP to Currency
/*INR*/    { 0.012,   1.22,  0.012,  0.011,     1, 0.017, 0.019, 0.091, 0.028,  0.17,   5.07,   1.80,   1.47, 10.8732,   17.35, 0.060,  0.24, 0.021,0.0047,   2.64,  0.044,    0.75, 0.017,   0.22,    0.44,   300.21,   3.03,  0.19},  // INR to Currency
/*CAD*/    {  0.73,  73.66,   0.74,   0.65, 60.37,     1,  1.15,  5.49,  1.68, 10.14, 305.87, 108.59,  88.40, 659.064, 1046.98,  3.64, 14.51,  1.28,  0.28, 159.52,   2.66,   44.94,  1.04,  13.58,   26.74, 18117.75, 182.56, 11.60},  // CAD to Currency
/*AUD*/    {  0.63,  63.88,   0.64,   0.56, 52.33,  0.87,     1,  4.76,  1.46,  8.80, 265.31,  94.16,  76.67, 572.043,  906.12,  3.16, 12.60,  1.11,  0.24, 138.29,   2.30,   38.73,  0.90,  11.76,   23.18, 15713.24, 158.22, 10.05},  // AUD to Currency
/*DKK*/    {  0.13,  13.41,   0.13,   0.12, 10.99,  0.18,  0.21,     1,  0.31,  1.85,  55.71,  19.77,  16.10, 118.263,  190.43,  0.66,  2.65,  0.23, 0.051,  29.05,   0.48,    8.13,  0.19,   2.47,    4.87,  3300.39,  33.23,  2.11},  // DKK to Currency
/*FJD*/    {  0.43,  43.70,   0.44,   0.38, 35.81,  0.59,  0.68,  3.26,     1,  6.02, 181.55,  64.43,  52.45,   385.7,  620.68,  2.16,  8.62,  0.76,  0.17,  94.66,   1.58,   26.51,  0.62,   8.05,   15.87, 10755.99, 108.31,  6.88},  // FJD to Currency
/*GHS*/    { 0.072,   7.26,  0.073,  0.064,  5.95, 0.099,  0.11,  0.54,   0.17,    1,  30.19,  10.71,   8.72,  64.585,  103.18,  0.36,  1.43,  0.13, 0.028,  15.74,   0.26,    4.41,  0.10,   1.34,    2.64,  1787.98,  18.00,  1.14},  // GHS to Currency
/*HUF*/    {0.0024,   0.24, 0.0024, 0.0021,  0.20,0.0033,0.0038, 0.018,0.0055, 0.033,      1,   0.36,   0.29, 2.14963,    3.43, 0.012, 0.048,0.0042,0.0009,   0.52, 0.0087,    0.15,0.0034,  0.044,   0.088,    59.34,  59.34, 0.038},  // HUF to Currency
/*JPY*/    {0.0067,   0.68, 0.0068, 0.0059,  0.56,0.0092, 0.011, 0.051, 0.016, 0.093,   2.81,      1,   0.81, 6.09346,    9.65, 0.034,  0.13, 0.012,0.0026,   1.47,  0.024,    0.41,0.0096,   0.12,    0.25,   166.78,   1.68,  0.11},  // JPY to Currency
/*KES*/    {0.0082,   0.83, 0.0084, 0.0073,  0.68, 0.011, 0.013, 0.062, 0.019,  0.11,   3.44,   1.23,      1,  7.4234,   11.84, 0.041,  0.16, 0.014,0.0032,   1.80,  0.030,    0.51, 0.012,   0.15,    0.30,   204.82,   2.06,  0.13},  // KES to Currency
/*KPW*/    {0.0011, 8.9303, 0.0011, 0.0009,0.0919,0.0015,0.0017,0.0084,0.0025,0.0147, 0.4649, 0.1592, 0.1346,       1,  1.5975,0.0056,0.0221,0.0019,0.0004, 0.2448, 0.0040,  0.0682,0.0015, 0.0206,  0.0408,  27.6724,   0.28,0.0176},  // KPW to Currency
/*KRW*/    {0.0007,  0.070,0.00071,0.00067, 0.058,0.0009,0.0011,0.0052,0.0016,0.0097,   0.29,   0.10,  0.084,  0.6234,       1,0.0035, 0.014,0.0012,0.0002,   0.15, 0.0025,   0.043,0.0009,  0.013,   0.026,    17.27,   0.17, 0.011},  // KRW to Currency
/*LYD*/    {  0.20,  20.26,   0.20,   0.18, 16.57,  0.27,  0.32,  1.51,  0.46,  2.78,  83.75,  29.81,  24.25,180.1480,  287.81,     1,  3.98,  0.35, 0.077,  43.78,   0.73,   12.35,  0.29,   3.73,    7.34,  4973.68,  50.10,  3.18},  // LYD to Currency
/*MXN*/    { 0.050,   5.07,  0.051,  0.044,  4.16, 0.069, 0.080,  0.38,  0.12,  0.70,  20.98,   7.48,   6.09,45.22829,   72.23,  0.25,     1, 0.088, 0.019,  10.99,   0.18,    3.10, 0.072,   0.94,    0.94,  1248.44,  12.57,  0.80},  // MXN to Currency
/*NZD*/    {  0.57,  57.37,   0.58,   0.50,  47.0,  0.78,  0.90,  4.28,  1.31,  7.89, 237.01,  84.53,  68.78, 512.404,  817.03,  2.84, 11.30,     1,  0.22, 124.18,   2.07,   34.96,  0.81,  10.56,   20.81, 14105.83, 142.02,  9.02},  // NZD to Currency
/*OMR*/    {  2.60, 262.26,   2.63,   2.29,214.86,  3.57,  4.12, 19.58,  6.01, 36.10,1084.02, 386.72, 314.73, 2337.41, 3732.27, 12.97, 51.70,  4.57,     1, 568.05,   9.46,  160.25,  3.70,  48.33,   95.23, 64554.13, 649.96, 41.30},  // OMR to Currency
/*PKR*/    {0.0046,   0.46, 0.0046, 0.0040,  0.38,0.0063,0.0073, 0.034, 0.011, 0.064,   1.91,   0.68,   0.55, 4.08485,    6.57, 0.023, 0.091,0.0081,0.0018,      1,  0.017,    0.28,0.0065,  0.085,    0.17,   113.65,   1.14, 0.073},  // PKR to Currency
/*QAR*/    {  0.27,  27.73,   0.28,   0.24, 22.73,  0.38,  0.44,  2.07,  0.64,  3.82, 114.69,  40.90,  33.28, 247.257,  394.90,  1.37,  5.47,  0.48,  0.11,  60.07,      1,   16.94,  0.39,   5.11,   10.07,  6825.95,  68.73,  4.37},  // QAR to Currency
/*RUB*/    { 0.016,   1.64,  0.016,  0.014,  1.34, 0.022, 0.026,  0.12, 0.038,  0.23,   6.77,   2.41,   1.96,  14.649,   23.31, 0.081,  0.32, 0.028,0.0062,   3.54,  0.059,       1, 0.023,   0.30,    0.59,   402.67,   4.05,  0.26},  // RUB to Currency
/*SGD*/    {  0.70,  70.86,   0.71,   0.62, 58.12,  0.96,  1.11,  5.29,  1.62,  9.75, 292.49, 104.52,  85.03, 635.885, 1010.33,  3.51, 13.98,  1.24,  0.27, 153.47,   2.55,   43.42,     1,  13.06,   25.73, 17444.61, 104.53, 11.16},  // SGD to Currency
/*TRY*/    { 0.054,   5.43,  0.054,  0.047,  4.45, 0.074, 0.085,  0.41,  0.12,  0.75,  22.43,   8.00,   6.51, 48.3673,   77.34,  0.27,  1.07, 0.095, 0.021,  11.75,   0.20,    3.31, 0.077,      1,    1.97,  1335.65,  13.45,  0.85},  // TRY to Currency
/*UAH*/    { 0.027,   2.75,  0.028,  0.024,  2.27, 0.037, 0.043,  0.21, 0.063,  0.38,  11.39,   4.06,   3.31,   24.11,   39.22,  0.14,  0.54, 0.048, 0.011,   5.97,   0.099,   1.68, 0.039,   0.51,       1,   677.91,   6.83,  0.43},  // UAH to Currency
/*VND*/    {.00040, 0.0043,.000041,.000036,0.0033,.00005,.00006,0.0003,.00009,0.0005,  0.017, 0.0060, 0.0049,   26.53,   0.058,0.0002,0.0008,.00007,.00001, 0.0088, 0.00015, 0.0025,.00005,0.00075,  0.0015,        1,  0.010,.00065},  // VND to Currency
/*YER*/    {0.0040,   0.42, 0.0041, 0.0035,  0.33,0.0055, 0.011, 0.030,0.0092, 0.056,   1.67,   0.59,   0.48,    3.59,    5.75, 0.020, 0.080,0.0070,0.0015,   0.88,   0.015,   0.25,0.0057,  0.074,    0.15,    99.32,      1, 0.064},  // YER to Currency
/*ZMW*/    { 0.062,   6.57,  0.063,  0.055,  5.15, 0.085, 0.098,  0.47,  0.14,  0.87,  26.06,   9.26,   7.54, 56.4593,   89.42,  0.31,  1.24,  0.11, 0.024,  13.66,    0.23,   3.86, 0.089,   1.16,    2.28,  1545.84,  15.56,     1},  // ZMW to Currency
};
//---------------------------- Mass Conversion Rates ----------------------------

const float conversionRates2[4][4] = {
    {1, 2.2046, 35.273, 1000},         // KG to Unit
    {0.4535, 1, 16, 453.592},          // PD to Unit
    {0.028, 0.0625, 1, 28.349},        // OU to Unit
    {0.001, 0.0022, 0.0352, 1},        // GM to Unit
};
//---------------------------- Length Conversion Rates ----------------------------

const float conversionRates3[8][8] = {
//              MM|     CM|      M|        KM|       IN|       FT|        YD|            MI|
/*MM*/    {      1,    0.1,  0.001,  0.000001,  0.03937, 0.003281, 0.0010936, 0.0000006214},  //MM to Unit
/*CM*/    {     10,      1,   0.01,    0.0001,   0.3937,  0.03281,  0.010936,  0.000006214},  //CM to Unit
/* M*/    {   1000,    100,      1,     0.001,    39.37,    3.281,    1.0936,    0.0006214},  // M to Unit
/*KM*/    {1000000, 100000,   1000,         1,    39370,     3281,    1093.6,       0.6214},  //KM to Unit
/*IN*/    {   25.4,   2.54, 0.0254, 0.0000254,        1,  0.08333,   0.02778,  0.000015783},  //IN to Unit
/*FT*/    {  304.8,  30.48, 0.3048, 0.0003048,       12,        1,   0.33333,    0.0001894},  //FT to Unit
/*YD*/    {  914.4,  91.44, 0.9144, 0.0009144,       36,        3,         1,    0.0005682},  //YD to Unit
/*MI*/    {1609344, 160934, 1609.3,    1.6093,    63360,     5280,      1760,            1},  //MI to Unit
};

int main() {
    int currency1, currency2, q, option, unit1, unit2,shape;
    const double amount, length, width, sides_Of_Square, base1, base2, height, radius_Of_Circle, radius_Of_Major_Axis, radius_Of_Minor_Axis;

for (;;)
{
    system("color F0");
    printf("                     \n");
    printf("                     \n");
    printf("                      ");
    printf("                     \n");
    printf("                     \n");
    printf("                      ");
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB ");
    printf("Welcome To Multi-Converter");
    printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("                     \n");
    printf("                      ");
    printf("--- Select Converter --- \n");
    printf("                      \n");
    printf("                      [0] Currency Converter                     \n"
           "                      \n"
           "                      [1] Weight Converter                         \n"
           "                      \n"
           "                      [2] Length Converter                       \n"
           "                      \n"
           "                      [3] Area Calculator                        \n");
    printf("                      \n");
    printf("                      Select 0 - 3\n");
    printf("                     \n");
    printf("                      ");
    printf("Now Select Options: ");
    scanf("%d", &option);

    if (option == 0)
    {
        //---------------------------- Currency Converter ----------------------------
        printf("                     \n");
        printf("                      ");
        printf("--- Currency converter --- \n");
        printf("                     \n");
        printf("                      ");
        printf("Options: \n");
        printf("                     \n");
        printf("                      ");
        printf("[0]  USD (United States Dollar)          [1]  BDT (Bangladeshi Taka)\n"
               "                      "
               "[2]  EUR (European Union)                [3]  GBP (Great Britain)\n"
               "                      "
               "[4]  INR (Indian Rupee)                  [5]  CAD (Canadian Dollar)\n"
               "                      "
               "[6]  AUD (Australian Dollar)             [7]  DKK (Danish Krone)\n"
               "                      "
               "[8]  FJD (Fijian Dollar)                 [9]  GHS (Ghanaian Cedi)\n"
               "                      "
               "[10] HUF (Hungarian Forint)              [11] JPY (Japanese Yen)\n"
               "                      "
               "[12] KES (Kenyan Shilling)               [13] KPW (North Korean Won)\n"
               "                      "
               "[14] KRW (South Korean Won)              [15] LYD (Libyan Dinar)\n"
               "                      "
               "[16] MXN (Mexican Peso)                  [17] NZD (New Zealand Dollar\n"
               "                      "
               "[18] OMR (Omani Rial)                    [19] PKR (Pakistani Rupee)\n"
               "                      "
               "[20] QAR (Qatari Riyal)                  [21] RUB (Russian Ruble)\n"
               "                      "
               "[22] SGD (Singapore dollar)              [23] TRY (Turkish Lira)\n"
               "                      "
               "[24] UAH (Ukrainian Hryvnia)             [25] VND (Vietnamese dong)\n"
               "                      "
               "[26] YER (Yemeni Rial)                   [27] ZMW (Zambian Kwacha)\n");

        //---------------------------- Taking Input/Clearing Invalid Input ----------------------------
        printf("                     \n");
        printf("                      ");
        printf("Enter currency1 (select 0-27): \n");
        printf("                     \n");
        printf("                      ");
        scanf("%d", &currency1);
        if (currency1 > 27 || currency1 < 0) {
            fflush(stdin);
            printf("                     \n");
            printf("                      ");
            printf("Invalid entry... Please select options 0-27 \n");
            continue;
        }
        printf("                     \n");
        printf("                      ");
        printf("Enter currency2 (select 0-27): \n");
        printf("                     \n");
        printf("                      ");
        scanf("%d", &currency2);
        if (currency2 > 27 || currency2 < 0) {
                printf("                     \n");
                printf("                      ");
            printf("Invalid entry... Please select options 0-5 \n");
            continue;
        }
        printf("                     \n");
        printf("                      ");
        printf("Enter amount: \n");
        printf("                     \n");
        printf("                      ");
        scanf("%lf", &amount);

        //---------------------------- Calculating Result ----------------------------

        float selectedRate = conversionRates[currency1][currency2];
        float totalAmount = selectedRate * amount;
        printf("                     \n");
        printf("                      ");
        printf("Converting %lf %s to %s: \n", amount, dictionary[currency1], dictionary[currency2]);
        printf("                     \n");
        printf("                      ");
        printf("Total amount = %f %s \n",totalAmount, dictionary[currency2]);
        fflush(stdin);

    } else if (option == 1)
    {
        //---------------------------- Mass Converter ----------------------------
        printf("                     \n");
        printf("                      ");
        printf("--- Weight converter --- \n");
        printf("                     \n");
        printf("                      ");
        printf("Options: \n");
        printf("                     \n");
        printf("                      ");
        printf("[0] KG\n"
               "                      "
               "[1] POUND\n"
               "                      "
               "[2] OUNCE\n"
               "                      "
               "[3] GRAM\n");

        //---------------------------- Taking Input/Clearing Invalid Input ----------------------------
        printf("                     \n");
        printf("                      ");
        printf("Enter unit1 (select 0-3): \n");
        printf("                     \n");
        printf("                      ");
        scanf("%d", &unit1);
        if (unit1 > 3 || unit1 < 0) {
            printf("                     \n");
            printf("                      ");
            printf("Invalid entry... Please select options 0-3 \n");
            continue;
        }
        printf("                     \n");
        printf("                      ");
        printf("Enter unit2 (select 0-3): \n");
        printf("                     \n");
        printf("                      ");
        scanf("%d", &unit2);
        if (unit2 > 3 || unit2 < 0) {
            printf("                     \n");
            printf("                      ");
            printf("Invalid entry... Please select options 0-3 \n");
            continue;
        }
        printf("                     \n");
        printf("                      ");
        printf("Enter amount: \n");
        printf("                     \n");
        printf("                      ");
        scanf("%lf", &amount);

        //---------------------------- Calculating Result ----------------------------

        float selectedRate = conversionRates2[unit1][unit2];
        float totalAmount = selectedRate * amount;
        printf("                     \n");
        printf("                      ");
        printf("Converting %f %s to %s: \n", amount, dictionary2[unit1], dictionary2[unit2]);
        printf("                     \n");
        printf("                      ");
        printf("Total amount = %f %s \n",totalAmount, dictionary2[unit2]);
        fflush(stdin);

       } else if (option == 2)
    {
        //---------------------------- Length Converter ----------------------------
        printf("                     \n");
        printf("                      ");
        printf("--- Length converter --- \n");
        printf("                     \n");
        printf("                      ");
        printf("Options: \n");
        printf("                     \n");
        printf("                      ");
        printf("[0] MM\n"
               "                      "
               "[1] CM\n"
               "                      "
               "[2] M\n"
               "                      "
               "[3] KM\n"
               "                      "
               "[4] IN\n"
               "                      "
               "[5] FT\n"
               "                      "
               "[6] YD\n"
               "                      "
               "[7] MI\n");

        //---------------------------- Taking Input/Clearing Invalid Input ----------------------------
        printf("                     \n");
        printf("                      ");
        printf("Enter unit1 (select 0-7): \n");
        printf("                     \n");
        printf("                      ");
        scanf("%d", &unit1);
            if (unit1 > 7 || unit1 < 0) {
                printf("                     \n");
                printf("                      ");
                printf("Invalid entry... Please select options 0-7 \n");
            continue;
            }
        printf("                     \n");
        printf("                      ");
        printf("Enter unit2 (select 0-7): \n");
        printf("                     \n");
        printf("                      ");
        scanf("%d", &unit2);
            if (unit2 > 7 || unit2 < 0) {
                printf("                     \n");
                printf("                      ");
                printf("Invalid entry... Please select options 0-3 \n");
            continue;
            }
        printf("                     \n");
        printf("                      ");
        printf("Enter amount: \n");
        printf("                     \n");
        printf("                      ");
        scanf("%lf", &amount);

        //---------------------------- Calculating Result ----------------------------

        float selectedRate = conversionRates3[unit1][unit2];
        float totalAmount = selectedRate * amount;
        printf("                     \n");
        printf("                      ");
        printf("Converting %lf %s to %s: \n", amount, unit_Names[unit1], unit_Names[unit2]);
        printf("                     \n");
        printf("                      ");
        printf("Total amount = %f %s \n",totalAmount, unit_Names[unit2]);
        fflush(stdin);

       } else if (option == 3)
       {
        //---------------------------- Area Calculator ----------------------------
        printf("                     \n");
        printf("                      ");
        printf("--- Area Calculator --- \n");
        printf("                     \n");
        printf("                      ");
        printf("Options: \n");
        printf("                     \n");
        printf("                      ");
        printf("[0] Rectangle\n"
               "                      "
               "[1] Square\n"
               "                      "
               "[2] Triangle\n"
               "                      "
               "[3] Circle\n"
               "                      "
               "[4] Trapezoid\n"
               "                      "
               "[5] Ellipse\n");

        //---------------------------- Taking Input/Clearing Invalid Input ----------------------------
        printf("                     \n");
        printf("                      ");
        printf("Select Shape (select 0-5): \n");
        printf("                     \n");
        printf("                      ");
        scanf("%d", &shape);
            if (shape > 5 || shape < 0) {
                printf("                     \n");
                printf("                      ");
                printf("Invalid entry... Please select options 0-5 \n");
                continue;
            }

        //---------------------------- Calculating Result ----------------------------

                if (shape == 0) {
                    printf("                     \n");
                    printf("                      ");
                    printf("Rectangle - \n");
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter length : ");
                    scanf("%lf", &length);
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter width : ");
                    scanf("%lf", &width);
                    printf("                     \n");
                    printf("                      ");

                    float area = length * width;

                    printf("Area : %f", area);


                } else if (shape == 1)

                {
                    printf("                     \n");
                    printf("                      ");
                    printf("Square - \n");
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter Sides of Square : ");
                    scanf("%lf", &sides_Of_Square);

                    float area = sides_Of_Square * sides_Of_Square;
                    printf("                     \n");
                    printf("                      ");
                    printf("Area : %f", area);

                } else if (shape == 2)

                {
                    printf("                     \n");
                    printf("                      ");
                    printf("Triangle - \n");
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter base : ");
                    scanf("%lf", &base1);
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter height : ");
                    scanf("%lf", &height);

                    float area = 0.5 * base1 * height;
                    printf("                     \n");
                    printf("                      ");
                    printf("Area : %f", area);

                } else if (shape == 3)
                {
                    printf("                     \n");
                    printf("                      ");
                    printf("Circle - \n");
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter radius of circle : ");
                    scanf("%lf", &radius_Of_Circle);

                    float area = 3.1416 * radius_Of_Circle * radius_Of_Circle;
                    printf("                     \n");
                    printf("                      ");
                    printf("Area : %f", area);

                } else if (shape == 4)
                {
                    printf("                     \n");
                    printf("                      ");
                    printf("Trapezoid - \n");
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter base1 : ");
                    scanf("%lf", &base1);
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter base2 : ");
                    scanf("%lf", &base2);
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter vertical height : ");
                    scanf("%lf", &height);

                    float area = 0.5 * (base1 + base2) * height;
                    printf("                     \n");
                    printf("                      ");
                    printf("Area : %f", area);

                } else if (shape == 5)
                {
                    printf("                     \n");
                    printf("                      ");
                    printf("Ellipse - \n");
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter radius of major axis : ");
                    scanf("%lf", &radius_Of_Major_Axis);
                    printf("                     \n");
                    printf("                      ");
                    printf("Enter radius of minor axis : ");
                    scanf("%lf", &radius_Of_Minor_Axis);

                    float area = 3.1416 * radius_Of_Major_Axis * radius_Of_Minor_Axis;
                    printf("                     \n");
                    printf("                      ");
                    printf("Area : %f", area);
                    fflush(stdin);

                }
       } else
       {
           printf("                     \n");
           printf("                      ");
           printf("Invalid entry... Please select options 0-3 \n");
           continue;
       }
       int exit = shouldExit();   // Exit Function
        if (exit == 2) {
            system("color F0");
            printf("                     \n");
            printf("                      ");
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB ");
            printf("Thank You For Using Multi-Converter");
            printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            break;
        }

    }
    getch();
}

