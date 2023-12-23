// 1. 矩阵水平翻折
for (int i = 0; i < n/2; ++i) {
    for (int j = 0; j < n; ++j) {
        swap(&matrix[i][j], &matrix[n-1 - i][j]);
    }
}

// 2. 矩阵左右翻折
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n/2; ++j) {
        swap(&matrix[i][j], &matrix[i][n-1 - j]);
    }
}

// 3. 矩阵主对角线翻折
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
        swap(&matrix[i][j], &matrix[j][i]);
    }
}

// 4. 矩阵副对角线翻折
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n-i; ++j) {
        swap(&matrix[i][j], &matrix[n-1 - j][n-1 - i]);
    }
}

// 5. 矩阵顺时针旋转90度
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n-i; ++j) {
        swap(&matrix[i][j], &matrix[n-1 - j][n-1 - i]);
    }
}
for (int i = 0; i < n/2; ++i) {
    for (int j = 0; j < n; ++j) {
        swap(&matrix[i][j], &matrix[n-1 - i][j]);
    }
}

// 6. 矩阵逆时针旋转90度
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
        swap(&matrix[i][j], &matrix[j][i]);
    }
}
for (int i = 0; i < n/2; ++i) {
    for (int j = 0; j < n; ++j) {
        swap(&matrix[i][j], &matrix[n-1 - i][j]);
    }
}
