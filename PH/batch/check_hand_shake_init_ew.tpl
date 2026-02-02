<!-- @@TITLE@@ -->
<h1>@@tpl_Title@@</h1>
<!-- @@TITLE@@ -->

<!-- @@TABLE_START@@ -->
<table class="@@TPL_NUM@@">
<!-- @@TABLE_START@@ -->

        <!-- @@TIMESTAMP@@ -->
        <tr>
                <th>Alert Time:</th>
                <td colspan="@@TIMESTAMP_NUM_COLUMNS@@">@@tpl_Timestamp@@</td>
        </tr>
        <!-- @@TIMESTAMP@@ -->

        <!-- @@ROW@@ -->
        <tr>
                <th>Merchant:</th>
                <td colspan="@@MERCHANT_NUM_COLUMNS@@">@@tpl_Merchant_Name@@ (@@tpl_Merchant_ID@@)</td>
        </tr>

        <tr>
                <th>Rate:</th>
                <td colspan="@@RATE_NUM_COLUMNS@@">@@tpl_Rate_Type@@</td>
                <td>@@tpl_Rate@@</td>
        </tr>

        <tr>
                <th></th>
                <td colspan="@@THRESHOLD_RATE_NUM_COLUMNS@@">@@tpl_Threshold_Rate_Type@@</td>
                <td>@@tpl_Threshold_Rate@@</td>
        </tr>

       		<!-- @@STATUS_ROW@@ -->
        	<tr>
                	<th>Status[@@tpl_Status_Num@@]:</th>
                	<td>@@tpl_Status@@</td>
                	<td>@@tpl_Sub_Status@@</td>
                	<td>@@tpl_Txn_Cnt@@</td>
        	</tr>
       		<!-- @@STATUS_ROW@@ -->

        <tr>
                <th colspan="@@TOTAL_TXN_CNT_NUM_COLUMNS@@">Total Transaction Count:</th>
                <td>@@tpl_Total_Txn_Cnt@@</td>
        </tr>

        <tr>
                <th>Duration:</th>
                <td colspan="@@DURATION_NUM_COLUMNS@@">@@tpl_Duration@@</td>
        </tr>
        <!-- @@ROW@@ -->

<!-- @@TABLE_END@@ -->
</table>
<!-- @@TABLE_END@@ -->
