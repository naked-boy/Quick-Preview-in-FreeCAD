# QuickPreview gui init module
# (c) 2001 Juergen Riegel LGPL

class QuickPreviewWorkbench ( Workbench ):
	"QuickPreview workbench object"
	MenuText = "QuickPreview"
	ToolTip = "QuickPreview workbench"
	def Initialize(self):
		# load the module
		import QuickPreviewGui
	def GetClassName(self):
		return "QuickPreviewGui::Workbench"

Gui.addWorkbench(QuickPreviewWorkbench())
