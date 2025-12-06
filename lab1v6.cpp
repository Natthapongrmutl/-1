#include <stdio.h>

// ฟังก์ชันสำหรับสร้างพื้นที่เก็บเมทริกและคืนค่า pointer
int *GetMatrix(int *rows, int *cols);

int main(){
    int *data;  // pointer สำหรับเก็บข้อมูลเมทริกซ์
    int totalRows;  // จำนวนแถว
    int totalCols;  // จำนวนคอลัมน์

    // เรียกฟังก์ชันเพื่อรับขนาดเมทริกซ์และจองหน่วยความจำ
    data = GetMatrix(&totalRows, &totalCols);

    // รับค่าของเมทริกซ์จากผู้ใช้
    printf("\nMatrix Input\n");
    for(int i = 0; i < totalRows; i++){
        printf("%d row\n",i+1);
        for(int colIndex = 0; colIndex < totalCols; colIndex++){
            printf("%d col number: ",colIndex+1);
            scanf("%d", &data[ i * totalCols + colIndex]);
        }
    }

    return 0;
}

// ------------------------- ฟังก์ชัน -------------------------
int *GetMatrix(int *numRows, int *numCols){
    int *varlueMatrix;  // ตัวแปรชั่วคราวสำหรับเก็บข้อมูลเมทริกซ์

    // รับจำนวนแถวและคอลัมน์จากผู้ใช้
    printf("enter rows, cols :");
    scanf("%d %d", numRows, numCols);

    // จองหน่วยความจำสำหรับเมทริกซ์แบบ 1 มิติ
    varlueMatrix = new int[ *numRows * *numCols];

    return varlueMatrix;
}
