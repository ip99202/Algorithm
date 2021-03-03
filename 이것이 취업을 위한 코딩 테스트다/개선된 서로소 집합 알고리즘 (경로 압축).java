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

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            merge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        System.out.print("각 원소가 속한 집합: ");
        for (int i = 1; i <= n; i++)
            System.out.print(find(i) + " ");
        System.out.println();
        System.out.print("부모 테이블: ");
        for (int i = 1; i <= n; i++)
            System.out.print(parent[i] + " ");
    }
}
