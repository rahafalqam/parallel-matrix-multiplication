// -------------------------------- Baseline (Single-threaded) Matrix Multiplication ----------------------------------
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define MAX 1000

// double A[MAX][MAX];
// double B[MAX][MAX];
// double C[MAX][MAX];

// void initialize(int N) {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             A[i][j] = rand() % 10;
//             B[i][j] = rand() % 10;
//             C[i][j] = 0;
//         }
//     }
// }

// void multiplyBaseline(int N) {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             C[i][j] = 0;
//             for (int k = 0; k < N; k++) {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }
// }

// int main() {
//     int N = 1000;  // عدلي هون: 100 او 500 او 1000

//     srand(0);
//     initialize(N);

//     clock_t start = clock();

//     multiplyBaseline(N);

//     clock_t end = clock();
//     double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

//     printf("Baseline Matrix Multiplication\n");
//     printf("Matrix size: %d x %d\n", N, N);
//     printf("Time taken: %f seconds\n", time_taken);

//     return 0;
// }

//-------------------------------- Row-wise Parallel Matrix Multiplication ----------------------------------
// #include <stdio.h>
// #include <stdlib.h>
// #include <windows.h>
// #include <pthread.h>

// #define MAX 1000

// double A[MAX][MAX];
// double B[MAX][MAX];
// double C[MAX][MAX];

// int N = 100;            // عدلي هون: 100 أو 500 أو 1000
// int NUM_THREADS = 16;   // عدلي هون: 2 أو 8 أو 16

// typedef struct {
//     int start_row;
//     int end_row;
// } ThreadData;

// void initialize() {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             A[i][j] = rand() % 10;
//             B[i][j] = rand() % 10;
//             C[i][j] = 0;
//         }
//     }
// }

// void* multiplyRowWise(void* arg) {
//     ThreadData* data = (ThreadData*) arg;

//     for (int i = data->start_row; i < data->end_row; i++) {
//         for (int j = 0; j < N; j++) {
//             C[i][j] = 0;
//             for (int k = 0; k < N; k++) {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }

//     return NULL;
// }

// int main() {
//     srand(0);

//     initialize();

//     pthread_t threads[NUM_THREADS];
//     ThreadData threadData[NUM_THREADS];

//     int rows_per_thread = N / NUM_THREADS;

//     LARGE_INTEGER freq, t0, t1;
//     QueryPerformanceFrequency(&freq);
//     QueryPerformanceCounter(&t0);

//     for (int i = 0; i < NUM_THREADS; i++) {
//         threadData[i].start_row = i * rows_per_thread;

//         if (i == NUM_THREADS - 1) {
//             threadData[i].end_row = N;
//         } else {
//             threadData[i].end_row = (i + 1) * rows_per_thread;
//         }

//         pthread_create(&threads[i], NULL, multiplyRowWise, &threadData[i]);
//     }

//     for (int i = 0; i < NUM_THREADS; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     QueryPerformanceCounter(&t1);
//     double time_taken = (double)(t1.QuadPart - t0.QuadPart) / freq.QuadPart;

//     printf("Row-wise Parallel Matrix Multiplication\n");
//     printf("Matrix size: %d x %d\n", N, N);
//     printf("Threads: %d\n", NUM_THREADS);
//     printf("Time taken: %f seconds\n", time_taken);

//     return 0;
// }

// -------------------------------- Column-wise Parallel Matrix Multiplication ----------------------------------
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <pthread.h>

// #define MAX 1000

// double A[MAX][MAX];
// double B[MAX][MAX];
// double C[MAX][MAX];

// int N           = 500;  // عدلي هون: 100 او 500 او 1000
// int NUM_THREADS = 16;    // عدلي هون: 2 او 8 او 16

// typedef struct {
//     int start_col;
//     int end_col;
// } ThreadData;

// void initialize() {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             A[i][j] = rand() % 10;
//             B[i][j] = rand() % 10;
//             C[i][j] = 0;
//         }
//     }
// }

// void* multiplyColumnWise(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     for (int i = 0; i < N; i++) {
//         for (int j = data->start_col; j < data->end_col; j++) {
//             C[i][j] = 0;
//             for (int k = 0; k < N; k++) {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }
//     return NULL;
// }

// int main() {
//     srand(0);
//     initialize();

//     pthread_t threads[NUM_THREADS];
//     ThreadData threadData[NUM_THREADS];
//     int cols_per_thread = N / NUM_THREADS;

//     clock_t start = clock();

//     for (int i = 0; i < NUM_THREADS; i++) {
//         threadData[i].start_col = i * cols_per_thread;
//         threadData[i].end_col   = (i == NUM_THREADS - 1) ? N : (i + 1) * cols_per_thread;
//         pthread_create(&threads[i], NULL, multiplyColumnWise, &threadData[i]);
//     }
//     for (int i = 0; i < NUM_THREADS; i++)
//         pthread_join(threads[i], NULL);

//     clock_t end = clock();
//     double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

//     printf("Column-wise Parallel Matrix Multiplication\n");
//     printf("Matrix size: %d x %d\n", N, N);
//     printf("Threads: %d\n", NUM_THREADS);
//     printf("Time taken: %f seconds\n", time_taken);

//     return 0;
// }

//  -------------------------------- Block (Tiled) Parallel Matrix Multiplication ----------------------------------
// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <time.h>

// #define MAX        1000
// #define SEED       0
// #define BLOCK_SIZE 250   // عدلي حسب التجربة

// double A[MAX][MAX];
// double B[MAX][MAX];
// double C[MAX][MAX];

// int N = 500;          // عدلي: 100 / 500 / 1000
// int num_threads = 2;  // عدلي: 2 / 8 / 16

// typedef struct {
//     int thread_id;
// } ThreadData;

// // تعبئة المصفوفات
// void initialize(void) {
//     srand(SEED);
//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++) {
//             A[i][j] = rand() % 10;
//             B[i][j] = rand() % 10;
//             C[i][j] = 0.0;
//         }
// }

// // دالة البلوك
// void* multiplyBlock(void* arg) {
//     ThreadData* data = (ThreadData*)arg;
//     int id = data->thread_id;

//     int tiles        = (N + BLOCK_SIZE - 1) / BLOCK_SIZE;
//     int total_blocks = tiles * tiles;

//     for (int b = id; b < total_blocks; b += num_threads) {

//         int bi = b / tiles;
//         int bj = b % tiles;

//         int row_start = bi * BLOCK_SIZE;
//         int col_start = bj * BLOCK_SIZE;

//         int row_end = (row_start + BLOCK_SIZE < N) ? row_start + BLOCK_SIZE : N;
//         int col_end = (col_start + BLOCK_SIZE < N) ? col_start + BLOCK_SIZE : N;

//         for (int i = row_start; i < row_end; i++) {
//             for (int j = col_start; j < col_end; j++) {

//                 double sum = 0.0;

//                 for (int k = 0; k < N; k++) {
//                     sum += A[i][k] * B[k][j];
//                 }

//                 C[i][j] = sum;
//             }
//         }
//     }

//     return NULL;
// }

// int main(void) {

//     initialize();

//     pthread_t threads[16];
//     ThreadData data[16];

//     clock_t start = clock();

//     // إنشاء الثريدز
//     for (int i = 0; i < num_threads; i++) {
//         data[i].thread_id = i;
//         pthread_create(&threads[i], NULL, multiplyBlock, &data[i]);
//     }

//     // انتظار انتهاء الثريدز
//     for (int i = 0; i < num_threads; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     clock_t end = clock();

//     double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

//     printf("=== Block (Tiled) Matrix Multiplication ===\n");
//     printf("Matrix size : %d x %d\n", N, N);
//     printf("Block size  : %d\n", BLOCK_SIZE);
//     printf("Threads     : %d\n", num_threads);
//     printf("Time taken  : %f seconds\n", elapsed);

//     return 0;
// }
