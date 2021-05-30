import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static int binarySearch(int target, boolean flag) {
        int st = 0, end = n;
        int res = (st + end) / 2;
        while (st <= end) {
            if (res < 0 || res >= n)
                return -1;
            if (arr[res] == target) {
                if (flag) {
                    if (res == 0 || arr[res - 1] != target) {
                        return res;
                    }
                    end = res - 1;
                } else if (!flag) {
                    if (res == n - 1 || arr[res + 1] != target) {
                        return res;
                    }
                    st = res + 1;
                }
            } else if (arr[res] < target) {
                st = res + 1;
            } else {
                end = res - 1;
            }
            res = (st + end) / 2;
        }
        return -1;
    }

    public static int n, m;
    public static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int start = binarySearch(m, true);
        if (start == -1) {
            System.out.println(-1);
        } else {
            int end = binarySearch(m, false);
            System.out.println(end - start + 1);
        }
        br.close();
    }
}