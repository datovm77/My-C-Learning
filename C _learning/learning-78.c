#include<stdio.h>
int main()
{
    int s, v;
    scanf("%d %d", &s, &v);
    
    // 向上取整计算走路时间
    int travel_time = (s + v - 1) / v;  //重点！！！向上取整！！！
    int total_time = travel_time + 10;  // 包括垃圾分类时间
    
    // 计算最晚出发时间（从当天00:00开始的分钟数）
    int departure_minutes = 480 - total_time; // 480是8:00的分钟数
    if (departure_minutes < 0) {
        departure_minutes += 1440; // 加上一天的分钟数，确保时间在前一天
    }
    
    int hour = departure_minutes / 60;
    int minute = departure_minutes % 60;
    
    // 格式化为两位输出
    printf("%02d:%02d", hour, minute);
    return 0;
}