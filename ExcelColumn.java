public class ExcelColumn {

    private static void displayColumnName(int columnNumber) {
        int[] column = new int[10000];
        int i = 0;

        while (columnNumber > 0) {
            column[i] = columnNumber % 26;
            columnNumber = columnNumber / 26;
            i++;
        }

        for (int j = 0; j < i - 1; j++) {
            if (column[j] <= 0) {
                column[j] += 26;
                column[j + 1] = column[j + 1] - 1;
            }
        }

        for (int j = i; j >= 0; j--)
            if (column[j] > 0)
                System.out.print((char) ('A' + column[j] - 1));

        System.out.println();
    }

    public static void main(String[] args) {
        displayColumnName(1);
        displayColumnName(26);
        displayColumnName(33);
        displayColumnName(313);

    }
}
