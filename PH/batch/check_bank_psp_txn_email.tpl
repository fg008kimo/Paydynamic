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

        <!-- @@BANK_TABLEHEAD@@ -->
        <tr>
                <th>PSP Account</th>
                <th>Bank Name</th>
                <th>Success Count</th>
                <th>Pending Count</th>
                <th>Total Count</th>
                <th>Success Rate</th>
                <th>Threshold Rate</th>
        </tr>
        <!-- @@BANK_TABLEHEAD@@ -->
        <!-- @@BANK_ROW@@ -->
        <tr>
                <td><b>@@tpl_PSP_Name@@</b> (@@tpl_PSP_ID@@)</td>
                <td>@@tpl_Bank_Name@@</td>
                <td>@@tpl_Success_Count@@</td>
                <td>@@tpl_Pending_Count@@</td>
                <td>@@tpl_Total_Count@@</td>
                <td>@@tpl_Success_Rate@@</td>
                <td>@@tpl_Threshold_Rate@@</td>
        </tr>
	<tr>
                <td align="right">Duration</th>
                <td colspan="@@DURATION_NUM_COLUMNS@@">@@tpl_Duration@@</td>
        </tr>
        <!-- @@BANK_ROW@@ -->

	</table>

<!-- @@TABLE_END@@ -->
</table>
<!-- @@TABLE_END@@ -->

