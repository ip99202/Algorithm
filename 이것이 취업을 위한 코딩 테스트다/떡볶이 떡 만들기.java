import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int n, m;

    public static int cal(int num, int[] arr) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > num)
                res += (arr[i] - num);
        }
        return res;
    }

    public static int binarySearch(int st, int end, int[] arr, int target) {
        while (st <= end) {
            int mid = (st + end) / 2;
            int flag = cal(mid, arr);
            if (flag == target)
                return mid;
            else if (flag > target)
                st = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int maxx = 0;
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            maxx = Integer.max(arr[i], maxx);
        }

        System.out.println(binarySearch(0, maxx, arr, m));
        br.close();
    }
}
/*
4 6
19 15 10 17
*/
