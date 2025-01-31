long largestRectangle(int h_count, int* h) {
    long max_area = 0;
    int* stack = malloc(h_count * sizeof(int));
    int top = -1;
    int i = 0;

    while (i < h_count) {
        if (top == -1 || h[i] >= h[stack[top]]) {
            stack[++top] = i++;
        } else {
            int height = h[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            long area = (long) height * width;
            if (area > max_area) {
                max_area = area;
            }
        }
    }

    while (top != -1){
        int height = h[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        long area = (long) height * width;
        if (area > max_area) {
            max_area = area;
        }
    }

    free(stack);
    return max_area;
}
