@@g_header@@
@@g_subject@@
@@g_htmlstart@@
<!-- @@stitle@@ -->
<h1>@@ftitle@@</h1>
<!-- @@stitle@@ -->
<!-- @@stable_start@@ -->
<table class="@@ftpl_num@@">
<!-- @@stable_start@@ -->
        <!-- @@stimestamp@@ -->
        <tr>
                <th>Alert Time:</th>
                <td colspan="3">@@ftimestamp@@</td>
        </tr>
        <!-- @@stimestamp@@ -->
        <!-- @@srow@@ -->
		<tr>
			<td colspan="4"></td>
		<tr>
        <tr>
                <th>Domain:</th>
                <td colspan="3">@@fdomain@@</td>
        </tr>
        <tr>
                <th>Rate:</th>
                <td colspan="2">@@frate_type@@</td>
                <td>@@frate@@%</td>
        </tr>
        <tr>
                <th></th>
                <td colspan="2">@@fthreshold_rate_type@@</td>
                <td>@@fthreshold_rate@@%</td>
        </tr>
		<!-- @@sstatus_row@@ -->
		<tr>
				<th>Status[@@fstatus_num@@]:</th>
				<td>@@fstatus@@</td>
				<td>@@fsub_status@@</td>
				<td>@@ftxn_cnt@@</td>
		</tr>
			<!-- @@stest@@ -->
			<tr>
				<th>Level 3 TEST</th>
				<td colspan="3">@@ftest@@</td>
			</tr>
			<!-- @@stest@@ -->
		<!-- @@sstatus_row@@ -->
        <tr>
                <th colspan="3" style="text-align:right">Total Transaction Count:</th>
                <td>@@ftotal_txn_cnt@@</td>
        </tr>
        <tr>
                <th>Duration:</th>
                <td colspan="3">@@fduration@@</td>
        </tr>
        <tr>
                <th>@@falert@@</th>
                <td colspan="3">@@falert_domain@@</td>
        </tr>
        <!-- @@srow@@ -->
<!-- @@stable_close@@ -->
</table>
<!-- @@stable_close@@ -->
@@g_htmlclose@@
