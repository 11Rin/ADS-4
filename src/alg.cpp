// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        cnt++;
      }
    }
  }
  return cnt;
}

int countPairs2(int *arr, int len, int value) {
  int cnt = 0;
  int start = 0;
  int end = len - 1;
  while (start < end) {
    if (arr[start] + arr[end] == value) {
      cnt++;
    }
    if (arr[start] + arr[end] < value) {
      start++;
    }
    else end--;
  }
  return cnt;
}

int countPairs3(int *arr, int len, int value) {
  int cnt = 0;
  int cur = 0;
  int mid = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i;
    int right = len;
    while (left < right - 1) {
      mid = (left + right) / 2;
      if (arr[i] + arr[mid] == value) {
        cnt++;
        cur = mid + 1;
        while (arr[i] + arr[cur] == value && cur < right) {
          cnt++;
          cur++;
        }
        cur = mid - 1;
        while (arr[i] + arr[cur] == value && cur > left) {
          cnt++;
          cur--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value) {
        right = mid;
      }
      else left = mid;
    }
  }
  return cnt;
}
