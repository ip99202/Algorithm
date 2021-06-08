import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static class Work implements Comparable<Work> {
        int st, end, pay;

        public Work(int st, int end, int pay) {
            this.st = st;
            this.end = end;
            this.pay = pay;
        }

        @Override
        public int compareTo(Work o) {
            if (this.end < o.end)
                return -1;
            return 1;
        }
    }

    public static int n, m;
    public static Work[] arr;
    public static int[] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new Work[n];
        dp = new int[n + 1];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i] = new Work(i, i + Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            dp[i] = 0;
        }
        Arrays.sort(arr);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].st > n || arr[i].end > n)
                continue;
            int tmp = 0;
            for (int j = 0; j <= arr[i].st; j++) {
                tmp = Integer.max(tmp, dp[j]);
                dp[j] = tmp;
            }
            dp[arr[i].end] = Integer.max(dp[arr[i].st] + arr[i].pay, dp[arr[i].end]);
            res = Integer.max(dp[arr[i].end], res);
        }
        System.out.println(res);
        br.close();
    }
}
