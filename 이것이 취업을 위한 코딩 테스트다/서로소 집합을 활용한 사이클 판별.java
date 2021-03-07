import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    public static void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;
    }

    public static boolean isUnion(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return true;
        else
            return false;
    }

    public static int n, m;
    public static int[] parent;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        boolean flag = false;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            merge(x, y);
            if (isUnion(x, y))
                flag = true;
        }
        if (flag)
            System.out.println("사이클이 발생했습니다.");
        else
            System.out.println("사이클이 발생하지 않았습니다.");
    }
}
