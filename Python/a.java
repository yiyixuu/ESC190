import java.util.*;

public class a {
    public static void main(String[] args) {
        int[][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        // for (int i = 0; i < arr.length; i++) {
        //     System.out.println(arr[i]);
        // }

        for (int[] i : arr) {
            for (int j : i) {
                System.out.print(j + " ");
            }
        }

    }
}

// [1, 2, 3, 4, 5, 6, 7, 8, 9] oldArray

// [1][4][7]
// [2][5][8]
// [3][6][9]

// row = 0 if(row%3==0) row = 0, col++
// col = 1

// arr[0][2]