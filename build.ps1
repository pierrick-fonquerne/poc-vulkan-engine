# Chemin du répertoire de construction
$buildDir = "build"

# Fonction pour afficher les messages colorés
function Write-Color {
    param(
        [string]$Message,
        [string]$Color = "White"
    )
    Write-Host $Message -ForegroundColor $Color
}

# Nettoyer le projet
if (Test-Path $buildDir) {
    Write-Color "Cleaning build directory..." "Blue"
    Remove-Item -Recurse -Force $buildDir
} else {
    Write-Color "No build directory to clean." "Yellow"
}

# Créer le répertoire de construction
New-Item -Path $buildDir -ItemType Directory

# Exécuter CMake pour configurer et compiler le projet
cd $buildDir

Write-Color "Running CMake configuration..." "Blue"
cmake .. | Out-Host

if ($?) {
    Write-Color "CMake configuration succeeded." "Green"
} else {
    Write-Color "CMake configuration failed." "Red"
    exit 1
}

Write-Color "Building the project..." "Blue"
cmake --build . | Out-Host

if ($?) {
    Write-Color "Build succeeded." "Green"
} else {
    Write-Color "Build failed." "Red"
    exit 1
}

# Revenir au répertoire racine
cd ..

Write-Color "Build process completed." "Green"
