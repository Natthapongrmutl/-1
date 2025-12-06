#include <stdio.h>

// ฟังก์ชันสำหรับรับค่าเมทริกจากผู้ใช้
void GetMatrix( int **value, int *rows, int *cols);

int main(){
    int *data;      // pointer สำหรับเเก็บข้อมูลเมทริก
    int totalRows;  // จำนวนแถว
    int totalCols;  // จำนวนคอลัมน์

    // เรียกฟังก์ชันเพื่อรับค่าเมทริก
    GetMatrix(&data, &totalCols, &totalRows);

    return 0;
}

//ฟังก์ชัน

void GetMatrix(int **value, int *numRows, int *numCols){
    int *varlueMatrix;  // ตัวแปรสำหรับเก็บข้อมูลเมทริก

    // รับจำนวนแถวและตอลัมน์จากผู่ใช้
    printf("enter rows, cols : ");
    scanf("%d %d", numRows, numCols);

    // จองหน่วยความจำสำหรับเมทริก
    varlueMatrix = new int[ *numRows * *numCols];

    // รับค่าของแต่ละสมาชิกในเมทริก
    for(int rowindex = 0; rowindex < *numRows; rowindex++){
        for(int colIndex = 0; colIndex < *numRows; colIndex++){
            printf("value[%d][%d] = ", rowindex, colIndex);
            scanf("%d", &varlueMatrix[ rowindex * * numCols + colIndex]);
        }
    }

    *value = varlueMatrix;
}
