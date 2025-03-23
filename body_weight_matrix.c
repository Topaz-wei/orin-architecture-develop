#include <stdio.h>
#include <stdlib.h>

int row = 2, col = 19;
//40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130共19个数
float cali_matrix[row][col] = {
    {40, 45, 50, 55, 60, 65,70,75,80,85,90,95,100,105,110,115,120,125,130},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}
};

int find_right_index(float body_weight, float cali_matrix[row][col])
{
    for(int i=0;i<col;i++)
    {
        if(body_weight <= cali_matrix[0][i])
            return i;
    }
    return -1;
}

//interpolation
void cali_body_weight(float *body_weight, float cali_matrix[row][col])
{
    int left_index, right_index;
    float cali_num, x1, x2, y1, y2;
    right_index = find_right_index(*body_weight, cali_matrix);
    left_index = right_index - 1;

    if(left_index < 0 || right_index == -1)
    {
        return;
    }

    x1 = cali_matrix[0][left_index];
    x2 = cali_matrix[0][right_index];
    y1 = cali_matrix[1][left_index];
    y2 = cali_matrix[1][right_index];
    cali_num = y1 + (y2 -y1)*(*body_weight - x1)/(x2 -x1);
    *body_weight += cali_num;
}

int main()
{
    float body_weight = 55.9;
    cali_body_weight(&body_weight, cali_matrix);
    printf("body_weight:%f\n", body_weight);
    return 0;
}