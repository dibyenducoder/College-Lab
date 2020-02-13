Public Class Form1
    Dim num1, num2, out
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        num1 = Val(TextBox1.Text)
        num2 = Val(TextBox2.Text)
        out = num1 + num2
        TextBox3.Text = out

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        num1 = Val(TextBox1.Text)
        num2 = Val(TextBox2.Text)
        out = num1 - num2
        TextBox3.Text = out

    End Sub

    
    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Button3.Text = Format("ADD-SUB")

    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Timer1.Start()
        Me.Text = String.Format(Today)

    End Sub

    
End Class
