<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.lb_name = New System.Windows.Forms.Label
        Me.Tb_name = New System.Windows.Forms.TextBox
        Me.Tb_phn = New System.Windows.Forms.TextBox
        Me.Tb_roll = New System.Windows.Forms.TextBox
        Me.lb_phn = New System.Windows.Forms.Label
        Me.lb_dept = New System.Windows.Forms.Label
        Me.Lb_roll = New System.Windows.Forms.Label
        Me.Button1 = New System.Windows.Forms.Button
        Me.Button2 = New System.Windows.Forms.Button
        Me.Button3 = New System.Windows.Forms.Button
        Me.Button5 = New System.Windows.Forms.Button
        Me.Button6 = New System.Windows.Forms.Button
        Me.Button7 = New System.Windows.Forms.Button
        Me.Button8 = New System.Windows.Forms.Button
        Me.Tb_addr = New System.Windows.Forms.TextBox
        Me.lb_addr = New System.Windows.Forms.Label
        Me.DataGridView1 = New System.Windows.Forms.DataGridView
        Me.Tb_search = New System.Windows.Forms.TextBox
        Me.Label1 = New System.Windows.Forms.Label
        Me.Panel1 = New System.Windows.Forms.Panel
        Me.cmb_dept = New System.Windows.Forms.ComboBox
        Me.Label2 = New System.Windows.Forms.Label
        CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.Panel1.SuspendLayout()
        Me.SuspendLayout()
        '
        'lb_name
        '
        Me.lb_name.AutoSize = True
        Me.lb_name.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lb_name.Location = New System.Drawing.Point(62, 81)
        Me.lb_name.Name = "lb_name"
        Me.lb_name.Size = New System.Drawing.Size(55, 20)
        Me.lb_name.TabIndex = 1
        Me.lb_name.Text = "Name"
        '
        'Tb_name
        '
        Me.Tb_name.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Tb_name.Location = New System.Drawing.Point(123, 74)
        Me.Tb_name.Name = "Tb_name"
        Me.Tb_name.Size = New System.Drawing.Size(270, 26)
        Me.Tb_name.TabIndex = 2
        '
        'Tb_phn
        '
        Me.Tb_phn.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Tb_phn.Location = New System.Drawing.Point(610, 117)
        Me.Tb_phn.Name = "Tb_phn"
        Me.Tb_phn.Size = New System.Drawing.Size(270, 26)
        Me.Tb_phn.TabIndex = 3
        '
        'Tb_roll
        '
        Me.Tb_roll.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Tb_roll.Location = New System.Drawing.Point(123, 117)
        Me.Tb_roll.Name = "Tb_roll"
        Me.Tb_roll.Size = New System.Drawing.Size(270, 26)
        Me.Tb_roll.TabIndex = 5
        '
        'lb_phn
        '
        Me.lb_phn.AutoSize = True
        Me.lb_phn.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lb_phn.Location = New System.Drawing.Point(506, 120)
        Me.lb_phn.Name = "lb_phn"
        Me.lb_phn.Size = New System.Drawing.Size(92, 20)
        Me.lb_phn.TabIndex = 6
        Me.lb_phn.Text = "Phone No."
        '
        'lb_dept
        '
        Me.lb_dept.AutoSize = True
        Me.lb_dept.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lb_dept.Location = New System.Drawing.Point(13, 175)
        Me.lb_dept.Name = "lb_dept"
        Me.lb_dept.Size = New System.Drawing.Size(104, 20)
        Me.lb_dept.TabIndex = 7
        Me.lb_dept.Text = "Department"
        '
        'Lb_roll
        '
        Me.Lb_roll.AutoSize = True
        Me.Lb_roll.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Lb_roll.Location = New System.Drawing.Point(77, 123)
        Me.Lb_roll.Name = "Lb_roll"
        Me.Lb_roll.Size = New System.Drawing.Size(40, 20)
        Me.Lb_roll.TabIndex = 8
        Me.Lb_roll.Text = "Roll"
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(123, 220)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 9
        Me.Button1.Text = "ADD"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(805, 479)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(75, 23)
        Me.Button2.TabIndex = 10
        Me.Button2.Text = "NEXT"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(12, 479)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(75, 23)
        Me.Button3.TabIndex = 11
        Me.Button3.Text = "PREV"
        Me.Button3.UseVisualStyleBackColor = True
        '
        'Button5
        '
        Me.Button5.Location = New System.Drawing.Point(328, 220)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(75, 23)
        Me.Button5.TabIndex = 13
        Me.Button5.Text = "DELETE"
        Me.Button5.UseVisualStyleBackColor = True
        '
        'Button6
        '
        Me.Button6.Location = New System.Drawing.Point(229, 220)
        Me.Button6.Name = "Button6"
        Me.Button6.Size = New System.Drawing.Size(75, 23)
        Me.Button6.TabIndex = 14
        Me.Button6.Text = "EDIT"
        Me.Button6.UseVisualStyleBackColor = True
        '
        'Button7
        '
        Me.Button7.Location = New System.Drawing.Point(229, 260)
        Me.Button7.Name = "Button7"
        Me.Button7.Size = New System.Drawing.Size(75, 23)
        Me.Button7.TabIndex = 18
        Me.Button7.Text = "CLOSE"
        Me.Button7.UseVisualStyleBackColor = True
        '
        'Button8
        '
        Me.Button8.Location = New System.Drawing.Point(805, 217)
        Me.Button8.Name = "Button8"
        Me.Button8.Size = New System.Drawing.Size(75, 23)
        Me.Button8.TabIndex = 17
        Me.Button8.Text = "SEARCH"
        Me.Button8.UseVisualStyleBackColor = True
        '
        'Tb_addr
        '
        Me.Tb_addr.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Tb_addr.Location = New System.Drawing.Point(610, 74)
        Me.Tb_addr.Name = "Tb_addr"
        Me.Tb_addr.Size = New System.Drawing.Size(270, 26)
        Me.Tb_addr.TabIndex = 19
        '
        'lb_addr
        '
        Me.lb_addr.AutoSize = True
        Me.lb_addr.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lb_addr.Location = New System.Drawing.Point(523, 80)
        Me.lb_addr.Name = "lb_addr"
        Me.lb_addr.Size = New System.Drawing.Size(75, 20)
        Me.lb_addr.TabIndex = 20
        Me.lb_addr.Text = "Address"
        '
        'DataGridView1
        '
        Me.DataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
        Me.DataGridView1.Location = New System.Drawing.Point(177, 289)
        Me.DataGridView1.Name = "DataGridView1"
        Me.DataGridView1.Size = New System.Drawing.Size(543, 222)
        Me.DataGridView1.TabIndex = 23
        '
        'Tb_search
        '
        Me.Tb_search.Location = New System.Drawing.Point(654, 217)
        Me.Tb_search.Name = "Tb_search"
        Me.Tb_search.Size = New System.Drawing.Size(143, 20)
        Me.Tb_search.TabIndex = 24
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 27.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.ForeColor = System.Drawing.SystemColors.Control
        Me.Label1.Location = New System.Drawing.Point(225, 3)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(381, 42)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "STUDENT RECORD"
        '
        'Panel1
        '
        Me.Panel1.BackColor = System.Drawing.Color.LightSlateGray
        Me.Panel1.Controls.Add(Me.Label1)
        Me.Panel1.Location = New System.Drawing.Point(12, 6)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(868, 52)
        Me.Panel1.TabIndex = 27
        '
        'cmb_dept
        '
        Me.cmb_dept.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.cmb_dept.FormattingEnabled = True
        Me.cmb_dept.Location = New System.Drawing.Point(123, 167)
        Me.cmb_dept.Name = "cmb_dept"
        Me.cmb_dept.Size = New System.Drawing.Size(270, 28)
        Me.cmb_dept.TabIndex = 29
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(564, 217)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(72, 20)
        Me.Label2.TabIndex = 30
        Me.Label2.Text = "Roll No."
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.RosyBrown
        Me.ClientSize = New System.Drawing.Size(892, 523)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.cmb_dept)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.Tb_search)
        Me.Controls.Add(Me.DataGridView1)
        Me.Controls.Add(Me.lb_addr)
        Me.Controls.Add(Me.Tb_addr)
        Me.Controls.Add(Me.Button7)
        Me.Controls.Add(Me.Button8)
        Me.Controls.Add(Me.Button6)
        Me.Controls.Add(Me.Button5)
        Me.Controls.Add(Me.Button3)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Lb_roll)
        Me.Controls.Add(Me.lb_dept)
        Me.Controls.Add(Me.lb_phn)
        Me.Controls.Add(Me.Tb_roll)
        Me.Controls.Add(Me.Tb_phn)
        Me.Controls.Add(Me.Tb_name)
        Me.Controls.Add(Me.lb_name)
        Me.Name = "Form1"
        Me.Text = "Student"
        CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.Panel1.ResumeLayout(False)
        Me.Panel1.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents lb_name As System.Windows.Forms.Label
    Friend WithEvents Tb_name As System.Windows.Forms.TextBox
    Friend WithEvents Tb_phn As System.Windows.Forms.TextBox
    Friend WithEvents Tb_roll As System.Windows.Forms.TextBox
    Friend WithEvents lb_phn As System.Windows.Forms.Label
    Friend WithEvents lb_dept As System.Windows.Forms.Label
    Friend WithEvents Lb_roll As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents Button6 As System.Windows.Forms.Button
    Friend WithEvents Button7 As System.Windows.Forms.Button
    Friend WithEvents Button8 As System.Windows.Forms.Button
    Friend WithEvents Tb_addr As System.Windows.Forms.TextBox
    Friend WithEvents lb_addr As System.Windows.Forms.Label
    Friend WithEvents DataGridView1 As System.Windows.Forms.DataGridView
    Friend WithEvents Tb_search As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents cmb_dept As System.Windows.Forms.ComboBox
    Friend WithEvents Label2 As System.Windows.Forms.Label

End Class
