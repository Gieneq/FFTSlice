#include "dac_sines.h"
#include <math.h>

const uint16_t dac_samples_values[DAC_SAMPLES_VALUES_COUNT] = {
 2048,  2245,  2441,  2632,  2818,  2996,  3166,  3324, 
 3471,  3603,  3721,  3822,  3907,  3973,  4021,  4050, 
 4060,  4050,  4021,  3973,  3907,  3822,  3721,  3603, 
 3471,  3324,  3166,  2996,  2818,  2632,  2441,  2245, 
 2048,  1851,  1655,  1464,  1278,  1100,   930,   772, 
  625,   493,   375,   274,   189,   123,    75,    46, 
   36,    46,    75,   123,   189,   274,   375,   493, 
  625,   772,   930,  1100,  1278,  1464,  1655,  1851, 
 2048,  2147,  2245,  2343,  2441,  2537,  2632,  2726, 
 2818,  2908,  2996,  3082,  3166,  3247,  3324,  3399, 
 3471,  3539,  3603,  3664,  3721,  3774,  3822,  3867, 
 3907,  3942,  3973,  4000,  4021,  4038,  4050,  4058, 
 4060,  4058,  4050,  4038,  4021,  4000,  3973,  3942, 
 3907,  3867,  3822,  3774,  3721,  3664,  3603,  3539, 
 3471,  3399,  3324,  3247,  3166,  3082,  2996,  2908, 
 2818,  2726,  2632,  2537,  2441,  2343,  2245,  2147, 
 2048,  1949,  1851,  1753,  1655,  1559,  1464,  1370, 
 1278,  1188,  1100,  1014,   930,   849,   772,   697, 
  625,   557,   493,   432,   375,   322,   274,   229, 
  189,   154,   123,    96,    75,    58,    46,    38, 
   36,    38,    46,    58,    75,    96,   123,   154, 
  189,   229,   274,   322,   375,   432,   493,   557, 
  625,   697,   772,   849,   930,  1014,  1100,  1188, 
 1278,  1370,  1464,  1559,  1655,  1753,  1851,  1949, 
 2048,  2097,  2147,  2196,  2245,  2294,  2343,  2392, 
 2441,  2489,  2537,  2585,  2632,  2679,  2726,  2772, 
 2818,  2863,  2908,  2953,  2996,  3040,  3082,  3124, 
 3166,  3207,  3247,  3286,  3324,  3362,  3399,  3435, 
 3471,  3505,  3539,  3572,  3603,  3634,  3664,  3693, 
 3721,  3748,  3774,  3799,  3822,  3845,  3867,  3887, 
 3907,  3925,  3942,  3958,  3973,  3987,  4000,  4011, 
 4021,  4030,  4038,  4045,  4050,  4055,  4058,  4059, 
 4060,  4059,  4058,  4055,  4050,  4045,  4038,  4030, 
 4021,  4011,  4000,  3987,  3973,  3958,  3942,  3925, 
 3907,  3887,  3867,  3845,  3822,  3799,  3774,  3748, 
 3721,  3693,  3664,  3634,  3603,  3572,  3539,  3505, 
 3471,  3435,  3399,  3362,  3324,  3286,  3247,  3207, 
 3166,  3124,  3082,  3040,  2996,  2953,  2908,  2863, 
 2818,  2772,  2726,  2679,  2632,  2585,  2537,  2489, 
 2441,  2392,  2343,  2294,  2245,  2196,  2147,  2097, 
 2048,  1999,  1949,  1900,  1851,  1802,  1753,  1704, 
 1655,  1607,  1559,  1511,  1464,  1417,  1370,  1324, 
 1278,  1233,  1188,  1143,  1100,  1056,  1014,   972, 
  930,   889,   849,   810,   772,   734,   697,   661, 
  625,   591,   557,   524,   493,   462,   432,   403, 
  375,   348,   322,   297,   274,   251,   229,   209, 
  189,   171,   154,   138,   123,   109,    96,    85, 
   75,    66,    58,    51,    46,    41,    38,    37, 
   36,    37,    38,    41,    46,    51,    58,    66, 
   75,    85,    96,   109,   123,   138,   154,   171, 
  189,   209,   229,   251,   274,   297,   322,   348, 
  375,   403,   432,   462,   493,   524,   557,   591, 
  625,   661,   697,   734,   772,   810,   849,   889, 
  930,   972,  1014,  1056,  1100,  1143,  1188,  1233, 
 1278,  1324,  1370,  1417,  1464,  1511,  1559,  1607, 
 1655,  1704,  1753,  1802,  1851,  1900,  1949,  1999, 
 2048,  2073,  2097,  2122,  2147,  2171,  2196,  2221, 
 2245,  2270,  2294,  2319,  2343,  2368,  2392,  2416, 
 2441,  2465,  2489,  2513,  2537,  2561,  2585,  2608, 
 2632,  2656,  2679,  2703,  2726,  2749,  2772,  2795, 
 2818,  2841,  2863,  2886,  2908,  2930,  2953,  2975, 
 2996,  3018,  3040,  3061,  3082,  3103,  3124,  3145, 
 3166,  3186,  3207,  3227,  3247,  3266,  3286,  3305, 
 3324,  3343,  3362,  3381,  3399,  3417,  3435,  3453, 
 3471,  3488,  3505,  3522,  3539,  3555,  3572,  3588, 
 3603,  3619,  3634,  3649,  3664,  3679,  3693,  3707, 
 3721,  3735,  3748,  3761,  3774,  3786,  3799,  3811, 
 3822,  3834,  3845,  3856,  3867,  3877,  3887,  3897, 
 3907,  3916,  3925,  3934,  3942,  3951,  3958,  3966, 
 3973,  3980,  3987,  3994,  4000,  4006,  4011,  4016, 
 4021,  4026,  4030,  4034,  4038,  4042,  4045,  4048, 
 4050,  4053,  4055,  4056,  4058,  4059,  4059,  4060, 
 4060,  4060,  4059,  4059,  4058,  4056,  4055,  4053, 
 4050,  4048,  4045,  4042,  4038,  4034,  4030,  4026, 
 4021,  4016,  4011,  4006,  4000,  3994,  3987,  3980, 
 3973,  3966,  3958,  3951,  3942,  3934,  3925,  3916, 
 3907,  3897,  3887,  3877,  3867,  3856,  3845,  3834, 
 3822,  3811,  3799,  3786,  3774,  3761,  3748,  3735, 
 3721,  3707,  3693,  3679,  3664,  3649,  3634,  3619, 
 3603,  3588,  3572,  3555,  3539,  3522,  3505,  3488, 
 3471,  3453,  3435,  3417,  3399,  3381,  3362,  3343, 
 3324,  3305,  3286,  3266,  3247,  3227,  3207,  3186, 
 3166,  3145,  3124,  3103,  3082,  3061,  3040,  3018, 
 2996,  2975,  2953,  2930,  2908,  2886,  2863,  2841, 
 2818,  2795,  2772,  2749,  2726,  2703,  2679,  2656, 
 2632,  2608,  2585,  2561,  2537,  2513,  2489,  2465, 
 2441,  2416,  2392,  2368,  2343,  2319,  2294,  2270, 
 2245,  2221,  2196,  2171,  2147,  2122,  2097,  2073, 
 2048,  2023,  1999,  1974,  1949,  1925,  1900,  1875, 
 1851,  1826,  1802,  1777,  1753,  1728,  1704,  1680, 
 1655,  1631,  1607,  1583,  1559,  1535,  1511,  1488, 
 1464,  1440,  1417,  1393,  1370,  1347,  1324,  1301, 
 1278,  1255,  1233,  1210,  1188,  1166,  1143,  1121, 
 1100,  1078,  1056,  1035,  1014,   993,   972,   951, 
  930,   910,   889,   869,   849,   830,   810,   791, 
  772,   753,   734,   715,   697,   679,   661,   643, 
  625,   608,   591,   574,   557,   541,   524,   508, 
  493,   477,   462,   447,   432,   417,   403,   389, 
  375,   361,   348,   335,   322,   310,   297,   285, 
  274,   262,   251,   240,   229,   219,   209,   199, 
  189,   180,   171,   162,   154,   145,   138,   130, 
  123,   116,   109,   102,    96,    90,    85,    80, 
   75,    70,    66,    62,    58,    54,    51,    48, 
   46,    43,    41,    40,    38,    37,    37,    36, 
   36,    36,    37,    37,    38,    40,    41,    43, 
   46,    48,    51,    54,    58,    62,    66,    70, 
   75,    80,    85,    90,    96,   102,   109,   116, 
  123,   130,   138,   145,   154,   162,   171,   180, 
  189,   199,   209,   219,   229,   240,   251,   262, 
  274,   285,   297,   310,   322,   335,   348,   361, 
  375,   389,   403,   417,   432,   447,   462,   477, 
  493,   508,   524,   541,   557,   574,   591,   608, 
  625,   643,   661,   679,   697,   715,   734,   753, 
  772,   791,   810,   830,   849,   869,   889,   910, 
  930,   951,   972,   993,  1014,  1035,  1056,  1078, 
 1100,  1121,  1143,  1166,  1188,  1210,  1233,  1255, 
 1278,  1301,  1324,  1347,  1370,  1393,  1417,  1440, 
 1464,  1488,  1511,  1535,  1559,  1583,  1607,  1631, 
 1655,  1680,  1704,  1728,  1753,  1777,  1802,  1826, 
 1851,  1875,  1900,  1925,  1949,  1974,  1999,  2023, 
 2048,  2060,  2073,  2085,  2097,  2110,  2122,  2134, 
 2147,  2159,  2171,  2184,  2196,  2208,  2221,  2233, 
 2245,  2257,  2270,  2282,  2294,  2307,  2319,  2331, 
 2343,  2355,  2368,  2380,  2392,  2404,  2416,  2428, 
 2441,  2453,  2465,  2477,  2489,  2501,  2513,  2525, 
 2537,  2549,  2561,  2573,  2585,  2597,  2608,  2620, 
 2632,  2644,  2656,  2667,  2679,  2691,  2703,  2714, 
 2726,  2737,  2749,  2761,  2772,  2784,  2795,  2807, 
 2818,  2829,  2841,  2852,  2863,  2875,  2886,  2897, 
 2908,  2919,  2930,  2942,  2953,  2964,  2975,  2986, 
 2996,  3007,  3018,  3029,  3040,  3050,  3061,  3072, 
 3082,  3093,  3103,  3114,  3124,  3135,  3145,  3156, 
 3166,  3176,  3186,  3196,  3207,  3217,  3227,  3237, 
 3247,  3256,  3266,  3276,  3286,  3296,  3305,  3315, 
 3324,  3334,  3343,  3353,  3362,  3372,  3381,  3390, 
 3399,  3408,  3417,  3426,  3435,  3444,  3453,  3462, 
 3471,  3479,  3488,  3497,  3505,  3514,  3522,  3530, 
 3539,  3547,  3555,  3563,  3572,  3580,  3588,  3595, 
 3603,  3611,  3619,  3627,  3634,  3642,  3649,  3657, 
 3664,  3671,  3679,  3686,  3693,  3700,  3707,  3714, 
 3721,  3728,  3735,  3741,  3748,  3754,  3761,  3767, 
 3774,  3780,  3786,  3792,  3799,  3805,  3811,  3817, 
 3822,  3828,  3834,  3840,  3845,  3851,  3856,  3862, 
 3867,  3872,  3877,  3882,  3887,  3892,  3897,  3902, 
 3907,  3912,  3916,  3921,  3925,  3930,  3934,  3938, 
 3942,  3947,  3951,  3955,  3958,  3962,  3966,  3970, 
 3973,  3977,  3980,  3984,  3987,  3990,  3994,  3997, 
 4000,  4003,  4006,  4008,  4011,  4014,  4016,  4019, 
 4021,  4024,  4026,  4028,  4030,  4032,  4034,  4036, 
 4038,  4040,  4042,  4043,  4045,  4046,  4048,  4049, 
 4050,  4051,  4053,  4054,  4055,  4055,  4056,  4057, 
 4058,  4058,  4059,  4059,  4059,  4060,  4060,  4060, 
 4060,  4060,  4060,  4060,  4059,  4059,  4059,  4058, 
 4058,  4057,  4056,  4055,  4055,  4054,  4053,  4051, 
 4050,  4049,  4048,  4046,  4045,  4043,  4042,  4040, 
 4038,  4036,  4034,  4032,  4030,  4028,  4026,  4024, 
 4021,  4019,  4016,  4014,  4011,  4008,  4006,  4003, 
 4000,  3997,  3994,  3990,  3987,  3984,  3980,  3977, 
 3973,  3970,  3966,  3962,  3958,  3955,  3951,  3947, 
 3942,  3938,  3934,  3930,  3925,  3921,  3916,  3912, 
 3907,  3902,  3897,  3892,  3887,  3882,  3877,  3872, 
 3867,  3862,  3856,  3851,  3845,  3840,  3834,  3828, 
 3822,  3817,  3811,  3805,  3799,  3792,  3786,  3780, 
 3774,  3767,  3761,  3754,  3748,  3741,  3735,  3728, 
 3721,  3714,  3707,  3700,  3693,  3686,  3679,  3671, 
 3664,  3657,  3649,  3642,  3634,  3627,  3619,  3611, 
 3603,  3595,  3588,  3580,  3572,  3563,  3555,  3547, 
 3539,  3530,  3522,  3514,  3505,  3497,  3488,  3479, 
 3471,  3462,  3453,  3444,  3435,  3426,  3417,  3408, 
 3399,  3390,  3381,  3372,  3362,  3353,  3343,  3334, 
 3324,  3315,  3305,  3296,  3286,  3276,  3266,  3256, 
 3247,  3237,  3227,  3217,  3207,  3196,  3186,  3176, 
 3166,  3156,  3145,  3135,  3124,  3114,  3103,  3093, 
 3082,  3072,  3061,  3050,  3040,  3029,  3018,  3007, 
 2996,  2986,  2975,  2964,  2953,  2942,  2930,  2919, 
 2908,  2897,  2886,  2875,  2863,  2852,  2841,  2829, 
 2818,  2807,  2795,  2784,  2772,  2761,  2749,  2737, 
 2726,  2714,  2703,  2691,  2679,  2667,  2656,  2644, 
 2632,  2620,  2608,  2597,  2585,  2573,  2561,  2549, 
 2537,  2525,  2513,  2501,  2489,  2477,  2465,  2453, 
 2441,  2428,  2416,  2404,  2392,  2380,  2368,  2355, 
 2343,  2331,  2319,  2307,  2294,  2282,  2270,  2257, 
 2245,  2233,  2221,  2208,  2196,  2184,  2171,  2159, 
 2147,  2134,  2122,  2110,  2097,  2085,  2073,  2060, 
 2048,  2036,  2023,  2011,  1999,  1986,  1974,  1962, 
 1949,  1937,  1925,  1912,  1900,  1888,  1875,  1863, 
 1851,  1839,  1826,  1814,  1802,  1789,  1777,  1765, 
 1753,  1741,  1728,  1716,  1704,  1692,  1680,  1668, 
 1655,  1643,  1631,  1619,  1607,  1595,  1583,  1571, 
 1559,  1547,  1535,  1523,  1511,  1499,  1488,  1476, 
 1464,  1452,  1440,  1429,  1417,  1405,  1393,  1382, 
 1370,  1359,  1347,  1335,  1324,  1312,  1301,  1289, 
 1278,  1267,  1255,  1244,  1233,  1221,  1210,  1199, 
 1188,  1177,  1166,  1154,  1143,  1132,  1121,  1110, 
 1100,  1089,  1078,  1067,  1056,  1046,  1035,  1024, 
 1014,  1003,   993,   982,   972,   961,   951,   940, 
  930,   920,   910,   900,   889,   879,   869,   859, 
  849,   840,   830,   820,   810,   800,   791,   781, 
  772,   762,   753,   743,   734,   724,   715,   706, 
  697,   688,   679,   670,   661,   652,   643,   634, 
  625,   617,   608,   599,   591,   582,   574,   566, 
  557,   549,   541,   533,   524,   516,   508,   501, 
  493,   485,   477,   469,   462,   454,   447,   439, 
  432,   425,   417,   410,   403,   396,   389,   382, 
  375,   368,   361,   355,   348,   342,   335,   329, 
  322,   316,   310,   304,   297,   291,   285,   279, 
  274,   268,   262,   256,   251,   245,   240,   234, 
  229,   224,   219,   214,   209,   204,   199,   194, 
  189,   184,   180,   175,   171,   166,   162,   158, 
  154,   149,   145,   141,   138,   134,   130,   126, 
  123,   119,   116,   112,   109,   106,   102,    99, 
   96,    93,    90,    88,    85,    82,    80,    77, 
   75,    72,    70,    68,    66,    64,    62,    60, 
   58,    56,    54,    53,    51,    50,    48,    47, 
   46,    45,    43,    42,    41,    41,    40,    39, 
   38,    38,    37,    37,    37,    36,    36,    36, 
   36,    36,    36,    36,    37,    37,    37,    38, 
   38,    39,    40,    41,    41,    42,    43,    45, 
   46,    47,    48,    50,    51,    53,    54,    56, 
   58,    60,    62,    64,    66,    68,    70,    72, 
   75,    77,    80,    82,    85,    88,    90,    93, 
   96,    99,   102,   106,   109,   112,   116,   119, 
  123,   126,   130,   134,   138,   141,   145,   149, 
  154,   158,   162,   166,   171,   175,   180,   184, 
  189,   194,   199,   204,   209,   214,   219,   224, 
  229,   234,   240,   245,   251,   256,   262,   268, 
  274,   279,   285,   291,   297,   304,   310,   316, 
  322,   329,   335,   342,   348,   355,   361,   368, 
  375,   382,   389,   396,   403,   410,   417,   425, 
  432,   439,   447,   454,   462,   469,   477,   485, 
  493,   501,   508,   516,   524,   533,   541,   549, 
  557,   566,   574,   582,   591,   599,   608,   617, 
  625,   634,   643,   652,   661,   670,   679,   688, 
  697,   706,   715,   724,   734,   743,   753,   762, 
  772,   781,   791,   800,   810,   820,   830,   840, 
  849,   859,   869,   879,   889,   900,   910,   920, 
  930,   940,   951,   961,   972,   982,   993,  1003, 
 1014,  1024,  1035,  1046,  1056,  1067,  1078,  1089, 
 1100,  1110,  1121,  1132,  1143,  1154,  1166,  1177, 
 1188,  1199,  1210,  1221,  1233,  1244,  1255,  1267, 
 1278,  1289,  1301,  1312,  1324,  1335,  1347,  1359, 
 1370,  1382,  1393,  1405,  1417,  1429,  1440,  1452, 
 1464,  1476,  1488,  1499,  1511,  1523,  1535,  1547, 
 1559,  1571,  1583,  1595,  1607,  1619,  1631,  1643, 
 1655,  1668,  1680,  1692,  1704,  1716,  1728,  1741, 
 1753,  1765,  1777,  1789,  1802,  1814,  1826,  1839, 
 1851,  1863,  1875,  1888,  1900,  1912,  1925,  1937, 
 1949,  1962,  1974,  1986,  1999,  2011,  2023,  2036, 
 2048,  2054,  2060,  2067,  2073,  2079,  2085,  2091, 
 2097,  2104,  2110,  2116,  2122,  2128,  2134,  2141, 
 2147,  2153,  2159,  2165,  2171,  2178,  2184,  2190, 
 2196,  2202,  2208,  2214,  2221,  2227,  2233,  2239, 
 2245,  2251,  2257,  2264,  2270,  2276,  2282,  2288, 
 2294,  2300,  2307,  2313,  2319,  2325,  2331,  2337, 
 2343,  2349,  2355,  2362,  2368,  2374,  2380,  2386, 
 2392,  2398,  2404,  2410,  2416,  2422,  2428,  2434, 
 2441,  2447,  2453,  2459,  2465,  2471,  2477,  2483, 
 2489,  2495,  2501,  2507,  2513,  2519,  2525,  2531, 
 2537,  2543,  2549,  2555,  2561,  2567,  2573,  2579, 
 2585,  2591,  2597,  2602,  2608,  2614,  2620,  2626, 
 2632,  2638,  2644,  2650,  2656,  2662,  2667,  2673, 
 2679,  2685,  2691,  2697,  2703,  2708,  2714,  2720, 
 2726,  2732,  2737,  2743,  2749,  2755,  2761,  2766, 
 2772,  2778,  2784,  2789,  2795,  2801,  2807,  2812, 
 2818,  2824,  2829,  2835,  2841,  2846,  2852,  2858, 
 2863,  2869,  2875,  2880,  2886,  2891,  2897,  2903, 
 2908,  2914,  2919,  2925,  2930,  2936,  2942,  2947, 
 2953,  2958,  2964,  2969,  2975,  2980,  2986,  2991, 
 2996,  3002,  3007,  3013,  3018,  3024,  3029,  3034, 
 3040,  3045,  3050,  3056,  3061,  3066,  3072,  3077, 
 3082,  3088,  3093,  3098,  3103,  3109,  3114,  3119, 
 3124,  3130,  3135,  3140,  3145,  3150,  3156,  3161, 
 3166,  3171,  3176,  3181,  3186,  3191,  3196,  3201, 
 3207,  3212,  3217,  3222,  3227,  3232,  3237,  3242, 
 3247,  3251,  3256,  3261,  3266,  3271,  3276,  3281, 
 3286,  3291,  3296,  3300,  3305,  3310,  3315,  3320, 
 3324,  3329,  3334,  3339,  3343,  3348,  3353,  3358, 
 3362,  3367,  3372,  3376,  3381,  3385,  3390,  3395, 
 3399,  3404,  3408,  3413,  3417,  3422,  3426,  3431, 
 3435,  3440,  3444,  3449,  3453,  3458,  3462,  3466, 
 3471,  3475,  3479,  3484,  3488,  3492,  3497,  3501, 
 3505,  3509,  3514,  3518,  3522,  3526,  3530,  3535, 
 3539,  3543,  3547,  3551,  3555,  3559,  3563,  3567, 
 3572,  3576,  3580,  3584,  3588,  3591,  3595,  3599, 
 3603,  3607,  3611,  3615,  3619,  3623,  3627,  3630, 
 3634,  3638,  3642,  3645,  3649,  3653,  3657,  3660, 
 3664,  3668,  3671,  3675,  3679,  3682,  3686,  3689, 
 3693,  3697,  3700,  3704,  3707,  3711,  3714,  3717, 
 3721,  3724,  3728,  3731,  3735,  3738,  3741,  3745, 
 3748,  3751,  3754,  3758,  3761,  3764,  3767,  3771, 
 3774,  3777,  3780,  3783,  3786,  3789,  3792,  3796, 
 3799,  3802,  3805,  3808,  3811,  3814,  3817,  3820, 
 3822,  3825,  3828,  3831,  3834,  3837,  3840,  3842, 
 3845,  3848,  3851,  3853,  3856,  3859,  3862,  3864, 
 3867,  3869,  3872,  3875,  3877,  3880,  3882,  3885, 
 3887,  3890,  3892,  3895,  3897,  3900,  3902,  3904, 
 3907,  3909,  3912,  3914,  3916,  3918,  3921,  3923, 
 3925,  3927,  3930,  3932,  3934,  3936,  3938,  3940, 
 3942,  3944,  3947,  3949,  3951,  3953,  3955,  3957, 
 3958,  3960,  3962,  3964,  3966,  3968,  3970,  3972, 
 3973,  3975,  3977,  3979,  3980,  3982,  3984,  3985, 
 3987,  3989,  3990,  3992,  3994,  3995,  3997,  3998, 
 4000,  4001,  4003,  4004,  4006,  4007,  4008,  4010, 
 4011,  4012,  4014,  4015,  4016,  4018,  4019,  4020, 
 4021,  4023,  4024,  4025,  4026,  4027,  4028,  4029, 
 4030,  4031,  4032,  4033,  4034,  4035,  4036,  4037, 
 4038,  4039,  4040,  4041,  4042,  4043,  4043,  4044, 
 4045,  4046,  4046,  4047,  4048,  4048,  4049,  4050, 
 4050,  4051,  4051,  4052,  4053,  4053,  4054,  4054, 
 4055,  4055,  4055,  4056,  4056,  4057,  4057,  4057, 
 4058,  4058,  4058,  4058,  4059,  4059,  4059,  4059, 
 4059,  4060,  4060,  4060,  4060,  4060,  4060,  4060, 
 4060,  4060,  4060,  4060,  4060,  4060,  4060,  4060, 
 4059,  4059,  4059,  4059,  4059,  4058,  4058,  4058, 
 4058,  4057,  4057,  4057,  4056,  4056,  4055,  4055, 
 4055,  4054,  4054,  4053,  4053,  4052,  4051,  4051, 
 4050,  4050,  4049,  4048,  4048,  4047,  4046,  4046, 
 4045,  4044,  4043,  4043,  4042,  4041,  4040,  4039, 
 4038,  4037,  4036,  4035,  4034,  4033,  4032,  4031, 
 4030,  4029,  4028,  4027,  4026,  4025,  4024,  4023, 
 4021,  4020,  4019,  4018,  4016,  4015,  4014,  4012, 
 4011,  4010,  4008,  4007,  4006,  4004,  4003,  4001, 
 4000,  3998,  3997,  3995,  3994,  3992,  3990,  3989, 
 3987,  3985,  3984,  3982,  3980,  3979,  3977,  3975, 
 3973,  3972,  3970,  3968,  3966,  3964,  3962,  3960, 
 3958,  3957,  3955,  3953,  3951,  3949,  3947,  3944, 
 3942,  3940,  3938,  3936,  3934,  3932,  3930,  3927, 
 3925,  3923,  3921,  3918,  3916,  3914,  3912,  3909, 
 3907,  3904,  3902,  3900,  3897,  3895,  3892,  3890, 
 3887,  3885,  3882,  3880,  3877,  3875,  3872,  3869, 
 3867,  3864,  3862,  3859,  3856,  3853,  3851,  3848, 
 3845,  3842,  3840,  3837,  3834,  3831,  3828,  3825, 
 3822,  3820,  3817,  3814,  3811,  3808,  3805,  3802, 
 3799,  3796,  3792,  3789,  3786,  3783,  3780,  3777, 
 3774,  3771,  3767,  3764,  3761,  3758,  3754,  3751, 
 3748,  3745,  3741,  3738,  3735,  3731,  3728,  3724, 
 3721,  3717,  3714,  3711,  3707,  3704,  3700,  3697, 
 3693,  3689,  3686,  3682,  3679,  3675,  3671,  3668, 
 3664,  3660,  3657,  3653,  3649,  3645,  3642,  3638, 
 3634,  3630,  3627,  3623,  3619,  3615,  3611,  3607, 
 3603,  3599,  3595,  3591,  3588,  3584,  3580,  3576, 
 3572,  3567,  3563,  3559,  3555,  3551,  3547,  3543, 
 3539,  3535,  3530,  3526,  3522,  3518,  3514,  3509, 
 3505,  3501,  3497,  3492,  3488,  3484,  3479,  3475, 
 3471,  3466,  3462,  3458,  3453,  3449,  3444,  3440, 
 3435,  3431,  3426,  3422,  3417,  3413,  3408,  3404, 
 3399,  3395,  3390,  3385,  3381,  3376,  3372,  3367, 
 3362,  3358,  3353,  3348,  3343,  3339,  3334,  3329, 
 3324,  3320,  3315,  3310,  3305,  3300,  3296,  3291, 
 3286,  3281,  3276,  3271,  3266,  3261,  3256,  3251, 
 3247,  3242,  3237,  3232,  3227,  3222,  3217,  3212, 
 3207,  3201,  3196,  3191,  3186,  3181,  3176,  3171, 
 3166,  3161,  3156,  3150,  3145,  3140,  3135,  3130, 
 3124,  3119,  3114,  3109,  3103,  3098,  3093,  3088, 
 3082,  3077,  3072,  3066,  3061,  3056,  3050,  3045, 
 3040,  3034,  3029,  3024,  3018,  3013,  3007,  3002, 
 2996,  2991,  2986,  2980,  2975,  2969,  2964,  2958, 
 2953,  2947,  2942,  2936,  2930,  2925,  2919,  2914, 
 2908,  2903,  2897,  2891,  2886,  2880,  2875,  2869, 
 2863,  2858,  2852,  2846,  2841,  2835,  2829,  2824, 
 2818,  2812,  2807,  2801,  2795,  2789,  2784,  2778, 
 2772,  2766,  2761,  2755,  2749,  2743,  2737,  2732, 
 2726,  2720,  2714,  2708,  2703,  2697,  2691,  2685, 
 2679,  2673,  2667,  2662,  2656,  2650,  2644,  2638, 
 2632,  2626,  2620,  2614,  2608,  2602,  2597,  2591, 
 2585,  2579,  2573,  2567,  2561,  2555,  2549,  2543, 
 2537,  2531,  2525,  2519,  2513,  2507,  2501,  2495, 
 2489,  2483,  2477,  2471,  2465,  2459,  2453,  2447, 
 2441,  2434,  2428,  2422,  2416,  2410,  2404,  2398, 
 2392,  2386,  2380,  2374,  2368,  2362,  2355,  2349, 
 2343,  2337,  2331,  2325,  2319,  2313,  2307,  2300, 
 2294,  2288,  2282,  2276,  2270,  2264,  2257,  2251, 
 2245,  2239,  2233,  2227,  2221,  2214,  2208,  2202, 
 2196,  2190,  2184,  2178,  2171,  2165,  2159,  2153, 
 2147,  2141,  2134,  2128,  2122,  2116,  2110,  2104, 
 2097,  2091,  2085,  2079,  2073,  2067,  2060,  2054, 
 2048,  2042,  2036,  2029,  2023,  2017,  2011,  2005, 
 1999,  1992,  1986,  1980,  1974,  1968,  1962,  1955, 
 1949,  1943,  1937,  1931,  1925,  1918,  1912,  1906, 
 1900,  1894,  1888,  1882,  1875,  1869,  1863,  1857, 
 1851,  1845,  1839,  1832,  1826,  1820,  1814,  1808, 
 1802,  1796,  1789,  1783,  1777,  1771,  1765,  1759, 
 1753,  1747,  1741,  1734,  1728,  1722,  1716,  1710, 
 1704,  1698,  1692,  1686,  1680,  1674,  1668,  1662, 
 1655,  1649,  1643,  1637,  1631,  1625,  1619,  1613, 
 1607,  1601,  1595,  1589,  1583,  1577,  1571,  1565, 
 1559,  1553,  1547,  1541,  1535,  1529,  1523,  1517, 
 1511,  1505,  1499,  1494,  1488,  1482,  1476,  1470, 
 1464,  1458,  1452,  1446,  1440,  1434,  1429,  1423, 
 1417,  1411,  1405,  1399,  1393,  1388,  1382,  1376, 
 1370,  1364,  1359,  1353,  1347,  1341,  1335,  1330, 
 1324,  1318,  1312,  1307,  1301,  1295,  1289,  1284, 
 1278,  1272,  1267,  1261,  1255,  1250,  1244,  1238, 
 1233,  1227,  1221,  1216,  1210,  1205,  1199,  1193, 
 1188,  1182,  1177,  1171,  1166,  1160,  1154,  1149, 
 1143,  1138,  1132,  1127,  1121,  1116,  1110,  1105, 
 1100,  1094,  1089,  1083,  1078,  1072,  1067,  1062, 
 1056,  1051,  1046,  1040,  1035,  1030,  1024,  1019, 
 1014,  1008,  1003,   998,   993,   987,   982,   977, 
  972,   966,   961,   956,   951,   946,   940,   935, 
  930,   925,   920,   915,   910,   905,   900,   895, 
  889,   884,   879,   874,   869,   864,   859,   854, 
  849,   845,   840,   835,   830,   825,   820,   815, 
  810,   805,   800,   796,   791,   786,   781,   776, 
  772,   767,   762,   757,   753,   748,   743,   738, 
  734,   729,   724,   720,   715,   711,   706,   701, 
  697,   692,   688,   683,   679,   674,   670,   665, 
  661,   656,   652,   647,   643,   638,   634,   630, 
  625,   621,   617,   612,   608,   604,   599,   595, 
  591,   587,   582,   578,   574,   570,   566,   561, 
  557,   553,   549,   545,   541,   537,   533,   529, 
  524,   520,   516,   512,   508,   505,   501,   497, 
  493,   489,   485,   481,   477,   473,   469,   466, 
  462,   458,   454,   451,   447,   443,   439,   436, 
  432,   428,   425,   421,   417,   414,   410,   407, 
  403,   399,   396,   392,   389,   385,   382,   379, 
  375,   372,   368,   365,   361,   358,   355,   351, 
  348,   345,   342,   338,   335,   332,   329,   325, 
  322,   319,   316,   313,   310,   307,   304,   300, 
  297,   294,   291,   288,   285,   282,   279,   276, 
  274,   271,   268,   265,   262,   259,   256,   254, 
  251,   248,   245,   243,   240,   237,   234,   232, 
  229,   227,   224,   221,   219,   216,   214,   211, 
  209,   206,   204,   201,   199,   196,   194,   192, 
  189,   187,   184,   182,   180,   178,   175,   173, 
  171,   169,   166,   164,   162,   160,   158,   156, 
  154,   152,   149,   147,   145,   143,   141,   139, 
  138,   136,   134,   132,   130,   128,   126,   124, 
  123,   121,   119,   117,   116,   114,   112,   111, 
  109,   107,   106,   104,   102,   101,    99,    98, 
   96,    95,    93,    92,    90,    89,    88,    86, 
   85,    84,    82,    81,    80,    78,    77,    76, 
   75,    73,    72,    71,    70,    69,    68,    67, 
   66,    65,    64,    63,    62,    61,    60,    59, 
   58,    57,    56,    55,    54,    53,    53,    52, 
   51,    50,    50,    49,    48,    48,    47,    46, 
   46,    45,    45,    44,    43,    43,    42,    42, 
   41,    41,    41,    40,    40,    39,    39,    39, 
   38,    38,    38,    38,    37,    37,    37,    37, 
   37,    36,    36,    36,    36,    36,    36,    36, 
   36,    36,    36,    36,    36,    36,    36,    36, 
   37,    37,    37,    37,    37,    38,    38,    38, 
   38,    39,    39,    39,    40,    40,    41,    41, 
   41,    42,    42,    43,    43,    44,    45,    45, 
   46,    46,    47,    48,    48,    49,    50,    50, 
   51,    52,    53,    53,    54,    55,    56,    57, 
   58,    59,    60,    61,    62,    63,    64,    65, 
   66,    67,    68,    69,    70,    71,    72,    73, 
   75,    76,    77,    78,    80,    81,    82,    84, 
   85,    86,    88,    89,    90,    92,    93,    95, 
   96,    98,    99,   101,   102,   104,   106,   107, 
  109,   111,   112,   114,   116,   117,   119,   121, 
  123,   124,   126,   128,   130,   132,   134,   136, 
  138,   139,   141,   143,   145,   147,   149,   152, 
  154,   156,   158,   160,   162,   164,   166,   169, 
  171,   173,   175,   178,   180,   182,   184,   187, 
  189,   192,   194,   196,   199,   201,   204,   206, 
  209,   211,   214,   216,   219,   221,   224,   227, 
  229,   232,   234,   237,   240,   243,   245,   248, 
  251,   254,   256,   259,   262,   265,   268,   271, 
  274,   276,   279,   282,   285,   288,   291,   294, 
  297,   300,   304,   307,   310,   313,   316,   319, 
  322,   325,   329,   332,   335,   338,   342,   345, 
  348,   351,   355,   358,   361,   365,   368,   372, 
  375,   379,   382,   385,   389,   392,   396,   399, 
  403,   407,   410,   414,   417,   421,   425,   428, 
  432,   436,   439,   443,   447,   451,   454,   458, 
  462,   466,   469,   473,   477,   481,   485,   489, 
  493,   497,   501,   505,   508,   512,   516,   520, 
  524,   529,   533,   537,   541,   545,   549,   553, 
  557,   561,   566,   570,   574,   578,   582,   587, 
  591,   595,   599,   604,   608,   612,   617,   621, 
  625,   630,   634,   638,   643,   647,   652,   656, 
  661,   665,   670,   674,   679,   683,   688,   692, 
  697,   701,   706,   711,   715,   720,   724,   729, 
  734,   738,   743,   748,   753,   757,   762,   767, 
  772,   776,   781,   786,   791,   796,   800,   805, 
  810,   815,   820,   825,   830,   835,   840,   845, 
  849,   854,   859,   864,   869,   874,   879,   884, 
  889,   895,   900,   905,   910,   915,   920,   925, 
  930,   935,   940,   946,   951,   956,   961,   966, 
  972,   977,   982,   987,   993,   998,  1003,  1008, 
 1014,  1019,  1024,  1030,  1035,  1040,  1046,  1051, 
 1056,  1062,  1067,  1072,  1078,  1083,  1089,  1094, 
 1100,  1105,  1110,  1116,  1121,  1127,  1132,  1138, 
 1143,  1149,  1154,  1160,  1166,  1171,  1177,  1182, 
 1188,  1193,  1199,  1205,  1210,  1216,  1221,  1227, 
 1233,  1238,  1244,  1250,  1255,  1261,  1267,  1272, 
 1278,  1284,  1289,  1295,  1301,  1307,  1312,  1318, 
 1324,  1330,  1335,  1341,  1347,  1353,  1359,  1364, 
 1370,  1376,  1382,  1388,  1393,  1399,  1405,  1411, 
 1417,  1423,  1429,  1434,  1440,  1446,  1452,  1458, 
 1464,  1470,  1476,  1482,  1488,  1494,  1499,  1505, 
 1511,  1517,  1523,  1529,  1535,  1541,  1547,  1553, 
 1559,  1565,  1571,  1577,  1583,  1589,  1595,  1601, 
 1607,  1613,  1619,  1625,  1631,  1637,  1643,  1649, 
 1655,  1662,  1668,  1674,  1680,  1686,  1692,  1698, 
 1704,  1710,  1716,  1722,  1728,  1734,  1741,  1747, 
 1753,  1759,  1765,  1771,  1777,  1783,  1789,  1796, 
 1802,  1808,  1814,  1820,  1826,  1832,  1839,  1845, 
 1851,  1857,  1863,  1869,  1875,  1882,  1888,  1894, 
 1900,  1906,  1912,  1918,  1925,  1931,  1937,  1943, 
 1949,  1955,  1962,  1968,  1974,  1980,  1986,  1992, 
 1999,  2005,  2011,  2017,  2023,  2029,  2036,  2042, 
};

/* Start , memptr         , Count , Div   , Freq[Hz]    */
const sinewave_data_t dac_samples_data[DAC_FREQ_STEPS] = {
	{  1984, dac_samples_values +   1984,   2048,   1562,     20.006F },
	{  1984, dac_samples_values +   1984,   2048,   1457,     21.448F },
	{  1984, dac_samples_values +   1984,   2048,   1359,     22.995F },
	{  1984, dac_samples_values +   1984,   2048,   1267,     24.665F },
	{  1984, dac_samples_values +   1984,   2048,   1182,     26.438F },
	{  1984, dac_samples_values +   1984,   2048,   1102,     28.358F },
	{  1984, dac_samples_values +   1984,   2048,   1028,     30.399F },
	{  1984, dac_samples_values +   1984,   2048,    959,     32.586F },
	{  1984, dac_samples_values +   1984,   2048,    894,     34.955F },
	{  1984, dac_samples_values +   1984,   2048,    834,      37.47F },
	{  1984, dac_samples_values +   1984,   2048,    778,     40.167F },
	{  1984, dac_samples_values +   1984,   2048,    725,     43.103F },
	{  1984, dac_samples_values +   1984,   2048,    676,     46.228F },
	{  1984, dac_samples_values +   1984,   2048,    631,     49.525F },
	{  1984, dac_samples_values +   1984,   2048,    588,     53.146F },
	{  1984, dac_samples_values +   1984,   2048,    549,     56.922F },
	{  1984, dac_samples_values +   1984,   2048,    512,     61.035F },
	{  1984, dac_samples_values +   1984,   2048,    477,     65.514F },
	{  1984, dac_samples_values +   1984,   2048,    445,     70.225F },
	{  1984, dac_samples_values +   1984,   2048,    415,     75.301F },
	{  1984, dac_samples_values +   1984,   2048,    387,     80.749F },
	{  1984, dac_samples_values +   1984,   2048,    361,     86.565F },
	{  1984, dac_samples_values +   1984,   2048,    337,      92.73F },
	{  1984, dac_samples_values +   1984,   2048,    314,     99.522F },
	{  1984, dac_samples_values +   1984,   2048,    293,    106.655F },
	{  1984, dac_samples_values +   1984,   2048,    273,    114.469F },
	{  1984, dac_samples_values +   1984,   2048,    255,    122.549F },
	{  1984, dac_samples_values +   1984,   2048,    237,    131.857F },
	{  1984, dac_samples_values +   1984,   2048,    221,    141.403F },
	{  1984, dac_samples_values +   1984,   2048,    207,    150.966F },
	{  1984, dac_samples_values +   1984,   2048,    193,    161.917F },
	{  1984, dac_samples_values +   1984,   2048,    180,    173.611F },
	{  1984, dac_samples_values +   1984,   2048,    168,    186.012F },
	{  1984, dac_samples_values +   1984,   2048,    156,    200.321F },
	{  1984, dac_samples_values +   1984,   2048,    146,    214.041F },
	{  1984, dac_samples_values +   1984,   2048,    136,    229.779F },
	{  1984, dac_samples_values +   1984,   2048,    127,    246.063F },
	{  1984, dac_samples_values +   1984,   2048,    118,    264.831F },
	{  1984, dac_samples_values +   1984,   2048,    110,    284.091F },
	{  1984, dac_samples_values +   1984,   2048,    103,    303.398F },
	{  1984, dac_samples_values +   1984,   2048,     96,    325.521F },
	{   960, dac_samples_values +    960,   1024,    179,    349.162F },
	{   960, dac_samples_values +    960,   1024,    167,    374.251F },
	{  1984, dac_samples_values +   1984,   2048,     78,    400.641F },
	{   960, dac_samples_values +    960,   1024,    145,    431.034F },
	{   960, dac_samples_values +    960,   1024,    135,    462.963F },
	{  1984, dac_samples_values +   1984,   2048,     63,    496.032F },
	{  1984, dac_samples_values +   1984,   2048,     59,    529.661F },
	{  1984, dac_samples_values +   1984,   2048,     55,    568.182F },
	{  1984, dac_samples_values +   1984,   2048,     51,    612.745F },
	{   448, dac_samples_values +    448,    512,    191,     654.45F },
	{   960, dac_samples_values +    960,   1024,     89,    702.247F },
	{   960, dac_samples_values +    960,   1024,     83,    753.012F },
	{   448, dac_samples_values +    448,    512,    155,    806.452F },
	{  1984, dac_samples_values +   1984,   2048,     36,    868.056F },
	{   448, dac_samples_values +    448,    512,    135,    925.926F },
	{   960, dac_samples_values +    960,   1024,     63,    992.063F },
	{   448, dac_samples_values +    448,    512,    117,   1068.376F },
	{   448, dac_samples_values +    448,    512,    109,   1146.789F },
	{   960, dac_samples_values +    960,   1024,     51,    1225.49F },
	{   448, dac_samples_values +    448,    512,     95,   1315.789F },
	{   192, dac_samples_values +    192,    256,    177,   1412.429F },
	{   192, dac_samples_values +    192,    256,    165,   1515.152F },
	{   448, dac_samples_values +    448,    512,     77,   1623.377F },
	{  1984, dac_samples_values +   1984,   2048,     18,   1736.111F },
	{   448, dac_samples_values +    448,    512,     67,   1865.672F },
	{   192, dac_samples_values +    192,    256,    125,     2000.0F },
	{    64, dac_samples_values +     64,    128,    233,   2145.923F },
	{   192, dac_samples_values +    192,    256,    109,   2293.578F },
	{    64, dac_samples_values +     64,    128,    203,   2463.054F },
	{    64, dac_samples_values +     64,    128,    189,   2645.503F },
	{  1984, dac_samples_values +   1984,   2048,     11,   2840.909F },
	{   448, dac_samples_values +    448,    512,     41,    3048.78F },
	{    64, dac_samples_values +     64,    128,    153,   3267.974F },
	{    64, dac_samples_values +     64,    128,    143,   3496.503F },
	{    64, dac_samples_values +     64,    128,    133,   3759.398F },
	{   448, dac_samples_values +    448,    512,     31,   4032.258F },
	{   448, dac_samples_values +    448,    512,     29,   4310.345F },
	{   448, dac_samples_values +    448,    512,     27,    4629.63F },
	{    64, dac_samples_values +     64,    128,    101,   4950.495F },
	{   192, dac_samples_values +    192,    256,     47,   5319.149F },
	{   960, dac_samples_values +    960,   1024,     11,   5681.818F },
	{   192, dac_samples_values +    192,    256,     41,   6097.561F },
	{     0, dac_samples_values +      0,     64,    153,   6535.948F },
	{    64, dac_samples_values +     64,    128,     71,   7042.254F },
	{     0, dac_samples_values +      0,     64,    133,   7518.797F },
	{   192, dac_samples_values +    192,    256,     31,   8064.516F },
	{     0, dac_samples_values +      0,     64,    116,    8620.69F },
	{   192, dac_samples_values +    192,    256,     27,   9259.259F },
	{     0, dac_samples_values +      0,     64,    100,    10000.0F },
	{    64, dac_samples_values +     64,    128,     47,  10638.298F },
	{     0, dac_samples_values +      0,     64,     87,  11494.253F },
	{     0, dac_samples_values +      0,     64,     81,  12345.679F },
	{   192, dac_samples_values +    192,    256,     19,  13157.895F },
	{     0, dac_samples_values +      0,     64,     71,  14084.507F },
	{    64, dac_samples_values +     64,    128,     33,  15151.515F },
	{     0, dac_samples_values +      0,     64,     62,  16129.032F },
	{     0, dac_samples_values +      0,     64,     57,   17543.86F },
	{     0, dac_samples_values +      0,     64,     54,  18518.519F },
	{    64, dac_samples_values +     64,    128,     25,    20000.0F },
};

