import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static int n, m;

    public static boolean binarySearch(int st, int end, int[] arr, int target) {
        while (st <= end) {
            int mid = (st + end) / 2;
            if (arr[mid] == target)
                return true;
            else if (arr[mid] > target)
                end = mid - 1;
            else
                st = mid + 1;
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        int[] arr1 = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr1[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr1);

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        int[] arr2 = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) arr2[i] = Integer.parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            if (!binarySearch(0, n - 1, arr1, arr2[i]))
                System.out.print("no ");
            else
                System.out.print("yes ");
        }
        br.close();
    }
}
