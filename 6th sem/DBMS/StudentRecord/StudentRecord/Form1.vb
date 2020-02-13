Imports System.Data
Imports System.Data.SqlClient

Public Class Form1
    Dim conn As SqlConnection
    Dim cmd As SqlCommand
    Dim da As SqlDataAdapter
    Dim dt As DataTable
    Dim cs As String
    Dim Index As Integer = 0

    Private Sub Student_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        bindgrid()
        showData(Index)

        cmb_dept.Items.Add("Architecture")
        cmb_dept.Items.Add("Chemical")
        cmb_dept.Items.Add("Civil")
        cmb_dept.Items.Add("Computer Science")
        cmb_dept.Items.Add("Construction")
        cmb_dept.Items.Add("Elecrical")
        cmb_dept.Items.Add("Electronics and Telecommunication")
        cmb_dept.Items.Add("Food Technology")
        cmb_dept.Items.Add("Information Technology")
        cmb_dept.Items.Add("Instrumentation and Electronics")
        cmb_dept.Items.Add("Mechanical")
        cmb_dept.Items.Add("Metallurgical")
        cmb_dept.Items.Add("Pharmaceutical")
        cmb_dept.Items.Add("Power")
        cmb_dept.Items.Add("Printing")
        cmb_dept.Items.Add("Production")
        cmb_dept.Items.Add("Others")

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        cs = "Data Source=HP\SQLEXPRESS ;Initial Catalog=demo ; Integrated Security = True"
        conn = New SqlConnection(cs)
        conn.Open()
        cmd = New SqlCommand("INSERT INTO student values('" + Tb_name.Text + "','" + Tb_roll.Text + "','" + cmb_dept.Text + "','" + Tb_addr.Text + "','" + Tb_phn.Text + "')", conn)

        Dim i As Integer = cmd.ExecuteNonQuery()
        If (i > 0) Then
            clear()
            MessageBox.Show("Record Add Successfully", "Hurrayy!", MessageBoxButtons.OK, MessageBoxIcon.Information)
            conn.Close()
            bindgrid()
        Else
            MsgBox("Sorry! Not Saved!")
        End If
        conn.Close()
    End Sub

    Private Sub clear()
        Tb_roll.Text = ""
        Tb_name.Clear()
        Tb_phn.Clear()
        Tb_addr.Clear()
        'Tb_dept.Clear()
        cmb_dept.Text = String.Empty
    End Sub

    Private Sub bindgrid()

        Using conn As New SqlConnection("Data Source=HP\SQLEXPRESS ;Initial Catalog=demo ; Integrated Security = True")
            conn.Open()
            Using cmd As New SqlCommand("SELECT * FROM student", conn)
                cmd.CommandType = CommandType.Text
                Using sda As New SqlDataAdapter(cmd)
                    Using dt As New DataTable()
                        sda.Fill(dt)
                        DataGridView1.DataSource = dt
                    End Using
                End Using
            End Using
        End Using
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        conn = New SqlConnection("Data Source=HP\SQLEXPRESS ;Initial Catalog=demo ; Integrated Security = True")
        conn.Open()
        cmd = New SqlCommand("delete from student where roll = '" & Tb_roll.Text & "' ", conn)
        cmd.ExecuteNonQuery()

        MsgBox("Record is deleted")
        Me.bindgrid()
        Tb_name.Clear()
        Tb_addr.Clear()
        Tb_phn.Clear()
        
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        conn = New SqlConnection("Data Source=HP\SQLEXPRESS ;Initial Catalog=demo ; Integrated Security = True")
        conn.Open()
        Dim ed = "update student set name = ' " & Tb_name.Text & "' , dept = ' " & cmb_dept.Text & " ',address=' " & Tb_addr.Text & " ',phn = ' " & Tb_phn.Text & " ' where roll = ' " + Tb_roll.Text + " ' "
        cmd = New SqlCommand(ed, conn)
        cmd.ExecuteNonQuery()
        MessageBox.Show("Updated !!!")
        clear()
        Me.bindgrid()
    End Sub

    Private Sub DataGridView1_CellClick(ByVal sender As System.Object, ByVal e As System.Windows.Forms.DataGridViewCellEventArgs) Handles DataGridView1.CellClick
        Dim i As Integer
        i = DataGridView1.CurrentRow.Index
        Try
            Tb_name.Text = DataGridView1.Item(0, i).Value
            Tb_roll.Text = DataGridView1.Item(1, i).Value
            cmb_dept.Text = DataGridView1.Item(2, i).Value
            Tb_addr.Text = DataGridView1.Item(3, i).Value
            Tb_phn.Text = DataGridView1.Item(4, i).Value

        Catch ex As Exception
            MsgBox("Cannot Be updated !!!")
        End Try
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        Try
            conn = New SqlConnection("Data Source=HP\SQLEXPRESS ;Initial Catalog=demo ; Integrated Security = True")
            conn.Open()

            cmd = New SqlCommand("select * from student where roll = @roll", conn)

            cmd.Parameters.Add("@roll", SqlDbType.Int).Value = Tb_search.Text

            Dim adp As New SqlDataAdapter(cmd)
            Dim table As New DataTable()
            adp.Fill(table)
            If (table.Rows.Count() > 0) Then
                DataGridView1.DataSource = table
                Tb_name.Text = table.Rows(0)(0).ToString
                Tb_roll.Text = table.Rows(0)(1).ToString
                cmb_dept.Text = table.Rows(0)(2).ToString
                Tb_addr.Text = table.Rows(0)(3).ToString
                Tb_phn.Text = table.Rows(0)(4).ToString
            Else
                MessageBox.Show("Data Not Found...")
            End If
        Catch ex As Exception
            MsgBox("Sorry ! No Record !")
        End Try
    End Sub

    Private Sub Tb_search_KeyUp(ByVal sender As System.Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles Tb_search.KeyUp
        If (Tb_search.Text = "") Then
            bindgrid()
        End If
    End Sub
    Public Sub showData(ByVal position As Integer)

        conn = New SqlConnection("Data Source=HP\SQLEXPRESS ;Initial Catalog=demo ; Integrated Security = True")
        conn.Open()

        Dim cmd As New SqlCommand("select * from student", conn)
        Dim adp As New SqlDataAdapter(cmd)
        Dim table As New DataTable()
        adp.Fill(table)
        Try
            Tb_name.Text = table.Rows(position)(0).ToString
            Tb_roll.Text = table.Rows(position)(1).ToString
            cmb_dept.Text = table.Rows(position)(2).ToString
            Tb_addr.Text = table.Rows(position)(3).ToString
            Tb_phn.Text = table.Rows(position)(4).ToString

        Catch ex As Exception
            conn.Close()
            MsgBox("End-point !")
        End Try
        


    End Sub
    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Index -= 1
        showData(Index)
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click

        Index += 1
        showData(Index)
    End Sub
End Class

